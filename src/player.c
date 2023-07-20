#include "genesis.h"

#include "player.h"
#include "collision.h"
#include "level.h"
#include "camera.h"
#include "sfx.h"
#include "utils.h"
//#include "lifebar.h"
#include "timer.h"
#include "res_sprite.h"
#include "hitbox.h"
#include "sguage.h"


#define ANIM_STAND          0
#define ANIM_ATTACK         1
#define ANIM_WALK           2
#define ANIM_RUN            3
#define ANIM_BRAKE          4
#define ANIM_UP             5
#define ANIM_CROUNCH        6
#define ANIM_ROLL           7
#define ANIM_UPPERCUT       8

#define RUN_SPEED           FIX32(6L)
#define BRAKE_SPEED         FIX32(2L)

#define ACCEL               FIX32(0.1)
#define DE_ACCEL            FIX32(0.15)

s16 check = 0;
int Senergy;
//Sguage = 100;
//setup hit BOX_coll


/*TODO:
Level starts with enemy pointing
ANIM_WAIT after a few seconds
if after 10 seconds run SPR_setAnim(player, ANIM_WAIT);
toggle between melee and spirit gun
NOTE:health packs should probably be in an array like enemies
health pack for player:DONE
spirit gauge for special moves:DONE
punch sound:DONE
//should set enemy flying
uppercut move:DONE
need to extend sprite sheet
animation when enemy hit
main menu:DONE
return to menu when player health is 0:
switch between spirit gun and melee
*/
// player (sonic) sprite
//Sprite* player;

// physic variables
fix32 maxSpeed;
fix32 jumpSpeed;
fix32 gravity;

s8 test;
// position and movement variables
//fix32 posX;
//fix32 posY;
//fix32 movX;
fix32 movY;
//s16 xOrder;
//s16 yOrder;
//int isAttacking;
int isBlocking;
//int A_Bpressed;
int isJumping;
u32 ss;
u16 timer;

s16 PLAYER_posX()

{
    return player->x;
}
s16 PLAYER_posY()

{
    return player->y;
}

u16 PLAYER_init(u16 vramIndex)
{
    // default speeds
    maxSpeed = MAX_SPEED_DEFAULT;
    jumpSpeed = JUMP_SPEED_DEFAULT;
    gravity = GRAVITY_DEFAULT;


    // set main sprite position (camera position may be adjusted depending it)
    posX = FIX32(30L);//48
    posY = MAX_POSY;
    movX = FIX32(0);
    movY = FIX32(0);
    xOrder = 0;
    yOrder = 0;

    //set up collision box
    PLAYER_hitbox.x = posX;
    PLAYER_hitbox.y = posY;
    PLAYER_hitbox.w = 16;
    PLAYER_hitbox.h = 40;//29
    // init sonic sprite//PAL0
    player = SPR_addSprite(&sonic_sprite, PLAYER_hitbox.x, PLAYER_hitbox.y, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));//0
    
    // do not used static vram allocation here
    return vramIndex;
}


void PLAYER_update(void)
{

    ///COLLISION_setup();
    //Sguage = 100;

     //PLAYER_special();
    // sonic physic, uupdate movement first
    if (xOrder > 0)
    {
        movX += ACCEL;
        // going opposite side, quick breaking
        if (movX < 0) movX += ACCEL;

        if (movX >= maxSpeed) movX = maxSpeed;
    }
    else if (xOrder < 0)
    {
        movX -= ACCEL;
        // going opposite side, quick breaking
        if (movX > 0) movX -= ACCEL;

        if (movX <= -maxSpeed) movX = -maxSpeed;
    }
    else
    {

        if ((movX < FIX32(0.1)) && (movX > FIX32(-0.1)))
            movX = 0;
        else if ((movX < FIX32(0.3)) && (movX > FIX32(-0.3)))
            movX -= movX >> 2;
        else if ((movX < FIX32(1)) && (movX > FIX32(-1)))
            movX -= movX >> 3;
        else
            movX -= movX >> 4;
    }

    // update position from movement
    posX += movX;
    posY += movY;

    // apply gravity if needed
    if (movY)
    {
        if (posY > MAX_POSY)
        {
            posY = MAX_POSY;
            movY = 0;
        }
        else movY += gravity;
    }
    // clip x pos
    if (posX >= MAX_POSX)
    {
        posX = MAX_POSX;
        movX = 0;
    }
    else if (posX <= MIN_POSX)
    {
        posX = MIN_POSX;
        movX = 0;
       // SPR_setAnim(player, ANIM_WAIT);
    }

    // finally update sprite state from internal state
    if (movY){ ss = 5;waitTick(ss);SPR_setAnim(player, ANIM_ROLL);}
    else
    {
        if (((movX >= BRAKE_SPEED) && (xOrder < 0)) || ((movX <= -BRAKE_SPEED) && (xOrder > 0)))
        {

            if (player->animInd != ANIM_BRAKE)
            {
                XGM_startPlayPCM(SFX_STOP, 1, SOUND_PCM_CH2);
                //SPR_setAnim(player, ANIM_BRAKE);//BRAKE
            }
        }
        else if ((movX >= RUN_SPEED) || (movX <= -RUN_SPEED))
          { 
            //SPR_setAnim(player, ANIM_RUN);
            SPR_setAnim(player, ANIM_RUN);//ANIM_WALK
        }
         else  if(isAttacking == 1)
            {
                
                ss = 5;//5
                
                XGM_startPlayPCM(SFX_PUNCH, 1, SOUND_PCM_CH2);
                //time the animation
               waitTick(ss);
                //waitMs(ss);
                //startTimer(timer);
                   
                SPR_setAnim(player,ANIM_ATTACK);
               

            }
       //test     
      else if(A_Bpressed == 1  )
      {
        
        ss = 5;//5
            
       waitTick(ss);

        SPR_setAnim(player,ANIM_UPPERCUT);
       // movY = -jumpSpeed;
        // PLAYER_action(5,8);

      }


       //test
        else if (movX != 0)
            SPR_setAnim(player, ANIM_WALK);
        else
        {
            if (yOrder < 0)
                SPR_setAnim(player, ANIM_UP);//ANIM_UP
            else if (yOrder > 0)
                SPR_setAnim(player, ANIM_CROUNCH);
            else
                SPR_setAnim(player, ANIM_STAND);//STAND
        }
    }

    if (movX > 0) SPR_setHFlip(player, FALSE);
    else if (movX < 0) SPR_setHFlip(player, TRUE);
    if (movX == 0){
         //start timer when idle
        //SPR_setAnim(player, ANIM_ATTACK);
    }
}
void PLAYER_action(u32 ticks,int arr[])
{
  ticks = 5;//5
            
       waitTick(ticks);

       if(arr[10] == 8)
       { 
        SPR_setAnim(player,ANIM_UPPERCUT);
        //movY += gravity;
       }
}
void PLAYER_updateScreenPosition(void)
{   //fix32ToInt(posX)
    setSpritePosition(player, fix32ToInt(posX) - camPosX, fix32ToInt(posY) - camPosY);
}


void PLAYER_handleInput(u16 value)
{
    u16 time = 10;
    //bloxk butto
    if (value & BUTTON_LMB) {
        //if isBlocking
        isBlocking = 1;
       E_hitbox->visibility = FALSE;
    }else{
        isBlocking = 0;
    }


    if (value & BUTTON_UP) {
        //isAttacking = 0;
        //yOrder = -1;
        //test
       //Sguage -= 10;

        //test
        //SPR_setAnim(sguage, GUAGE_ANIM_70);
    }
    if (value & BUTTON_A) {
       //spirit energy uses 1 points. need to fix guage increments
        Sguage -= 1;
     
        switch(Sguage)
   {
   case 90: SPR_setAnim(sguage, GUAGE_ANIM_90);
      break;
   case 80: SPR_setAnim(sguage, GUAGE_ANIM_80);
      break;
   case 70: SPR_setAnim(sguage, GUAGE_ANIM_70);
      break;  

      default:
         KLog_U1("test:", Sguage);
   }

    //SPR_setAnim(sguage, GUAGE_ANIM_70);
 

    }
    if(value & BUTTON_UP  )//&& BUTTON_A
    {
       //uppercut attack
        A_Bpressed = 1;
       //SPR_setAnim(player,ANIM_UPPERCUT);
    }else{
        A_Bpressed = 0;
    }
    

    if (value & BUTTON_B) 
    {
        isAttacking = 1;
    }else{
       
        isAttacking = 0;
    }


    //projectile
    if (value & BUTTON_C) yOrder = -1;  //projectile yOrder = -1;
    //if (value & BUTTON_B) isAttacking = 1;
    //else isAttacking = 0;
    else if (value & BUTTON_DOWN) yOrder = +1;
    else yOrder = 0;

    if (value & BUTTON_LEFT) xOrder = -1;
    else if (value & BUTTON_RIGHT) xOrder = +1;
    else xOrder = 0;

}

void PLAYER_doJoyAction(u16 joy, u16 changed, u16 state)
{   //BUTTON_A | BUTTON_B | BUTTON_C | BUTTON_X | BUTTON_Y | BUTTON_Z
    if (changed & state & (BUTTON_C ))
    {
       
        
        if (movY == 0)
        {   // isJumping = 1;
            movY = -jumpSpeed;
            XGM_startPlayPCM(SFX_JUMP, 1, SOUND_PCM_CH2);


        }
    }
}
