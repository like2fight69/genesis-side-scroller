#include "genesis.h"

#include "projectile.h"
#include "level.h"
#include "camera.h"
#include "sfx.h"
#include "utils.h"
//#include "player.h"
#include "res_sprite.h"

#define ANIM_Wait          0

#define SPEED           FIX32(6L)
#define ACCEL               FIX32(0.1)
//Sprite* projectile;
//
fix32 SPd;

//
//fix32 posY;
fix32 PROJ_movX;
fix32 movY;
s16 xOrd;
s16 yOrder;


u16 PROJECTILE_init(u16 vramIndex)
{

    PROJ_posX = FIX32(30L);//30
    posY = MAX_POSY;
    PROJ_movX = FIX32(0l);
    //movY = FIX32(0);
    //xOrd = 0;
    yOrder = 0;
   //setup collision BOX_coll
   PROJ_box->x = PROJ_posX;
   PROJ_box->y = posY;
   PROJ_box->w = 16;
   PROJ_box->h = 29;


	projectile = SPR_addSprite(&projectile_sprite, PROJ_box->x, PROJ_box->y, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
     return vramIndex;
}

void PROJECTILE_update(void)
{
   if(xOrd > 0)
   {
   	 //PROJ_posX += FIX32(9.5);
   }

    // update position from movement



}
void PROJECTILE_updateScreenPosition(void)
{
    setSpritePosition(projectile, fix32ToInt(PROJ_posX) - camPosX, fix32ToInt(posY) - camPosY);
}
void PROJECTILE_handleInput(u16 value)
{
   if (value & BUTTON_C)
    {
       //player->x += FIX32(3.0);
    	xOrd = +1;
      KLog_U1("int:", xOrd);
    	//PROJ_posX += FIX32(1.5);
        //movX += FIX32(30L);

    }

}
