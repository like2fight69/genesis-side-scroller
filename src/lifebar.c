#include "genesis.h"

#include "player.h"
#include "collision.h"
#include "level.h"
#include "camera.h"
#include "sfx.h"
#include "utils.h"
#include "lifebar.h"
#include "timer.h"
#include "res_sprite.h"


//#define ANIM_90         1

u16 LIFEBAR_init(u16 vramIndex)
{
    // default speeds
    //maxSpeed = MAX_SPEED_DEFAULT;
    //jumpSpeed = JUMP_SPEED_DEFAULT;
    //gravity = GRAVITY_DEFAULT;
u16 ind;
    u16 numTile;
lifebar = SPR_addSprite(&lifebar_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));//0
//sguage = SPR_addSprite(&sguage_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));//0
   //SPR_setFrameChangeCallback(lifebar, &frameChanged);
     ind = vramIndex;
      ind += numTile;
    //lifebar = SPR_addSprite(&lifebar_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));//0
   //lifebar[0]->data = 15;
    // do not used static vram allocation here
    return ind;
}

