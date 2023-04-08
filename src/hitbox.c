#include "genesis.h"

#include "player.h"
#include "collision.h"
#include "level.h"
#include "camera.h"
#include "sfx.h"
#include "utils.h"

#include "hitbox.h"
#include "res_sprite.h"

#define ENEMY_HITBOX          0
//check sgdk header files
//flip hitbox when player turns:DONE
// physic variables
fix32 maxSpeed;
fix32 jumpSpeed;
fix32 gravity;

// convert PLAYER_hitbox.x to fix32
//fix32 posX;
//fix32 posY;
fix32 movX;
fix32 movY;
s16 xOrder;
s16 yOrder;
//fix32 Xpos;
//fix32 Ypos;
int ENEMIES_HIT_x;
int ENEMIES_HIT_y;

u16 HITBOX_init(u16 vramIndex)
{

    Xpos = FIX32(30L);
    BOX_width = FIX32(25L);//25
    ENEMIES_width = FIX32(-10L);//-10
    PLAYER_hitbox.x = posX;//0;//posX;
    PLAYER_hitbox.y = MAX_POSY;//0;//posY;
    
    PLAYER_hitbox.w = 32;
    PLAYER_hitbox.h = 32;//need to find actual width and height
    ENEMIES_hitbox.w = 32;
    ENEMIES_hitbox.h = 32;

    ENEMIES_hitbox.x = enemiesPosX[1];//Xpos; //posX;//enemiesPosX[NUM_ENEMY];//posX;//0;//posX;
    ENEMIES_hitbox.y = enemiesPosY[1];//MAX_POSY;//enemiesPosY[NUM_ENEMY];//0;//posY;
    ENEMIES_HIT_x = fix32Int(ENEMIES_hitbox.x);
    ENEMIES_HIT_y = fix32Int(ENEMIES_hitbox.y);


   // ENEMIES_hitbox.w = 32;
   // ENEMIES_hitbox.h = 32;


    //need to add hitbox_sprite variable to sprite res
    // init sonic sprite
    P_hitbox = SPR_addSprite(&hitbox_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));//0
    E_hitbox = SPR_addSprite(&hitbox_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));
     //SPR_setVisibility(E_hitbox,VISIBLE);
    // do not used static vram allocation here
    return vramIndex;

}
void HITBOX_update()
{
  
   //E_hitbox = SPR_addSprite(&hitbox_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));
  

    if (movX > 0) SPR_setHFlip(P_hitbox, TRUE);//FALSE
    else if (movX < 0) SPR_setHFlip(P_hitbox, FALSE);//TRUE
}
void HITBOX_updateScreenPosition(void)
{   //set hitbox positions to entites posX,posY fix32ToInt(posX)
    setSpritePosition(P_hitbox, fix32ToInt(posX) - camPosX, fix32ToInt(posY) - camPosY);
   // setSpritePosition(E_hitbox, fix32ToInt(posX) - camPosX, fix32ToInt(posY) - camPosY);
   // setSpritePosition(E_hitbox, ENEMIES_hitbox.x , ENEMIES_hitbox.y );//140
  // setSpritePosition(E_hitbox, fix32ToInt(ENEMIES_hitbox.x) - camPosX, fix32ToInt(ENEMIES_hitbox.y) - camPosY);
  //setSpritePosition(E_hitbox, fix32ToInt(ENEMIES_HIT_x) - camPosX, fix32ToInt(ENEMIES_HIT_y) - camPosY);
}

