#include "genesis.h"

#include "player.h"
#include "collision.h"
#include "items.h"
#include "camera.h"
#include "sfx.h"
#include "utils.h"
//#include "lifebar.h"
#include "timer.h"
#include "res_sprite.h"
#include "level.h"

//make array of items like entities
u16 ITEMS_init(u16 vramIndex)
{
   
u16 ind;
    u16 numTile;
healthpackPosX[0] = FIX32(128L);
    healthpackPosY[0] = MAX_POSY + FIX32(5);

healthpack[0] = SPR_addSprite(&healthpack_sprite, healthpackPosX[0], healthpackPosY[0], TILE_ATTR(PAL0, TRUE, FALSE, FALSE));//0

    return vramIndex;
}
void ITEMS_updateScreenPosition()
{

    setSpritePosition(healthpack[0], fix32ToInt(healthpackPosX[0]) - camPosX, fix32ToInt(healthpackPosY[0]) - camPosY);
}