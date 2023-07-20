#ifndef _ENTITIES_H_
#define _ENTITIES_H_

#define NUM_ENEMY       2
#define ENTITiE_ANIM_ATTACK 2
#define GRAV_DEFAULT     FIX32(0.36)

u16 ENTITIES_init(u16 vramIndex);
Sprite* enemies[NUM_ENEMY];
fix32 enemiesPosX[NUM_ENEMY];
fix32 enemiesPosY[NUM_ENEMY];
fix32 moveY;
fix32 jmpSpd;
fix32 gravit;
int entitieIsAttacking;
s16 enemiesXOrder[NUM_ENEMY];
void ENTITIES_update(void);
void ENTITIES_updateScreenPosition();


#endif // _ENTITIES_H_
