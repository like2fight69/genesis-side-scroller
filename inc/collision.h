#ifndef _COLLISION_H_
#define _COLLISION_H_
//#include "sprite_eng.h"
#include "genesis.h"
//#include "hitbox.h"
//#include "sguage.h"
int hasCollided;
#define NUM_COLLISION_OBJS      2
Sprite* COLLISION_objs[NUM_COLLISION_OBJS];
fix32 blocksPosX[NUM_COLLISION_OBJS];
fix32 blocksPosY[NUM_COLLISION_OBJS];

 //bool RECT_rect(HIT_box A, HIT_box B);
void COLLISION_setup();
void BLOCKS_updateScreenPosition();
//void checkWeaponEnemyCollision(const SpriteDefinition* projDef, const SpriteDefinition* enemyDef);

#endif
