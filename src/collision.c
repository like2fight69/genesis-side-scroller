#include "genesis.h"
#include "collision.h"
#include "player.h"
#include "lifebar.h"
//#include "projectile.h"
#include "camera.h"
#include "entities.h"
#include "res_sprite.h"
#include "hitbox.h"
#include "items.h"
#include "level.h"
//#include "darray.h"
//#include "sguage.h"
#define false 0
#define true 1
//create collision box for player and enemy:DONE
//BoxCollision BOX_coll;

 fix32 s_buffer = 4;//4
 int HEA = 100;
//check pointer to struct
 /*bool RECT_rect(HIT_box A, HIT_box B)
{
    fix32 aHBuf = A.h / s_buffer;
    fix32 aWBuf = A.w / s_buffer;

    fix32 bHBuf = B.h / s_buffer;
    fix32 bWBuf = B.w / s_buffer;

    // if the bottom of A is less than the top of B - no collision
    if((A.y + A.h) - aHBuf <= B.y + bHBuf)  { return false; }

    // if the top of A is more than the bottom of B = no collision
    if(A.y + aHBuf >= (B.y + B.h) - bHBuf)  { return false; }

    // if the right of A is less than the left of B - no collision
    if((A.x + A.w) - aWBuf <= B.x +  bWBuf) { return false; }

    // if the left of A is more than the right of B - no collision
    if(A.x + aWBuf >= (B.x + B.w) - bWBuf)  { return false; }
    if(A.x + aWBuf == (B.x + B.w) - bWBuf)  { return true; }
     
    // otherwise there has been a collision
    return true;
}*/







void COLLISION_setup()
{       //&& isAttacking == 1
     /*if(posX < Xpos + BOX_width && isAttacking == 1 ){//posX < PLAYER_hitbox.x
    // do things
 
   int v = 100;
//KDebug_AlertNumber(v);
   hasCollided = 1;
   KLog_U1("test:", hasCollided);
   //SPR_setNeverVisible(&hitbox_sprite, TRUE);
   //SPR_setHFlip(E_hitbox, TRUE);
    //SPR_setHFlip(P_hitbox, TRUE);
   SPR_releaseSprite(E_hitbox);
  //SPR_setNeverVisible(E_hitbox, TRUE);
  //SPR_setVisibility(E_hitbox,HIDDEN);



}*/ 
  blocksPosX[0] = FIX32(300L);
    blocksPosY[0] = MAX_POSY - FIX32(0);//100


COLLISION_objs[0] = SPR_addSprite(&block_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));
if(blocksPosX[0] < enemiesPosX[1] + BOX_width && blocksPosX[0]  > enemiesPosX[1])
{
   SPR_setHFlip(enemies[1], TRUE);
   //enemiesPosX[1] -= FIX32(0.7);
 enemiesXOrder[1] = -1;
}



//BOX_ith 
if(blocksPosX[0] < posX + BOX_width && blocksPosX[0]  > posX)
{
    //stop movement and scrolling background
    //movX = 0;
   //resets player position
   posX = FIX32(30L);
}


if(healthpackPosX[0] < posX + BOX_width && healthpackPosX[0] + ENEMIES_width > posX)
{
   
   HEA += 10;
    switch(HEA)
   {
   case 90: SPR_setAnim(lifebar, ANIM_90);
      break;
   case 80: SPR_setAnim(lifebar, ANIM_80);
      break;
   case 70: SPR_setAnim(lifebar, ANIM_70);
      break;  

      default:
         KLog_U1("test:", HEA);
   }
   //remove healthpack
   //SPR_releaseSprite(healthpack[0]);

}

if(enemiesPosX[1] < posX + BOX_width && enemiesPosX[1] + ENEMIES_width > posX && !isAttacking)
{
   HEA -= 10;
   entitieIsAttacking = 1;
   //run sprite animation

   switch(HEA)
   {
   case 90: SPR_setAnim(lifebar, ANIM_90);
      break;
   case 80: SPR_setAnim(lifebar, ANIM_80);
      break;
   case 70: SPR_setAnim(lifebar, ANIM_70);
      break;  

      default:
         KLog_U1("test:", HEA);
   }


}




  /*if(posX + BOX_width < enemies[1]  && isAttacking == 1) //posX < enemiesPosX[1]  && isAttacking == 1
  {
      KLog_U1("test:", 200);
      enemiesPosY[1] -= FIX32(30l);
      //SPR_releaseSprite(enemies[1]);
  }*/


 //need to increase enemy width + ENEMIES_width
 //need to make enemy bounce like player jump
if(enemiesPosX[1] < posX + BOX_width && enemiesPosX[1] + ENEMIES_width > posX  && A_Bpressed == 1) //posX < enemiesPosX[1]  && isAttacking == 1
  {
      KLog_U1("test:", 200);
      //SPR_releaseSprite(enemies[1]);
      // enemiesPosY[1] -= FIX32(30l);
       if (moveY == 0)
        {   // isJumping = 1;
            moveY = -jmpSpd;
            //XGM_startPlayPCM(SFX_JUMP, 1, SOUND_PCM_CH2);


        }
      //SPR_setAnim(lifebar, ANIM_90);
  }


  if(enemiesPosX[1] < posX + BOX_width && enemiesPosX[1] + ENEMIES_width > posX  && isAttacking == 1) //posX < enemiesPosX[1]  && isAttacking == 1
  {
      KLog_U1("test:", 200);
     // SPR_releaseSprite(enemies[1]);
      
       //enemiesPosY[1] -= FIX32(30l);
      
  }
   
   
   /*if(RECT_rect(PLAYER_hitbox,ENEMIES_hitbox)){//posX < PLAYER_hitbox.x
	// do things
 
   int v = 100;
//KDebug_AlertNumber(v);
   KLog_U1("test:", v);
  
}
*/

}

void BLOCKS_updateScreenPosition()
{

   setSpritePosition(COLLISION_objs[0], fix32ToInt(blocksPosX[0]) - camPosX, fix32ToInt(blocksPosY[0]) - camPosY);

}
