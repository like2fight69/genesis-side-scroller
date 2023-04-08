#ifndef _HITBOX_H_
#define _HITBOX_H_
#include "player.h"
#include "entities.h"
#include "genesis.h"
#include "collision.h"

typedef struct
{
   fix32 x;
    fix32 y;
    u8 w;
    u8 h;
}HIT_box;


HIT_box PLAYER_hitbox;
HIT_box ENEMIES_hitbox;
Sprite* P_hitbox;
Sprite* E_hitbox;
fix32 Xpos;
fix32 Ypos;
fix32 BOX_width;
fix32 ENEMIES_width;

u16 HITBOX_init(u16 vramIndex);
void HITBOX_updateScreenPosition(void);
void HITBOX_update(void);
#endif
