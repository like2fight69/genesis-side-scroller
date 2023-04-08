#include "genesis.h"

#include "player.h"
#include "collision.h"
#include "level.h"
#include "camera.h"
#include "sfx.h"
#include "utils.h"
#include "sguage.h"
#include "timer.h"
#include "res_sprite.h"


//#define ANIM_90         1

u16 SGUAGE_init(u16 vramIndex)
{
   

    Sguage = 100;
//lifebar = SPR_addSprite(&lifebar_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));//0
sguage = SPR_addSprite(&sguage_sprite, 0, 0, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));//0
   
    return vramIndex;
}
