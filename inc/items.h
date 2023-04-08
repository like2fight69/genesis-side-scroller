#ifndef _ITEMS_H_
#define _ITEMS_H_

#define healthpack_ANIM         0
#define NUM_HEALTH       2




Sprite* healthpack[NUM_HEALTH];
fix32 healthpackPosX[NUM_HEALTH];
fix32 healthpackPosY[NUM_HEALTH];

u16 ITEMS_init(u16 vramIndex); //= 100;
void ITEMS_updateScreenPosition();
#endif