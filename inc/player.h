#ifndef _PLAYER_H_
#define _PLAYER_H_


#define MAX_SPEED_MAX       FIX32(20L)
#define MAX_SPEED_MIN       FIX32(1L)
#define MAX_SPEED_DEFAULT   FIX32(8L)

#define JUMP_SPEED_MIN      FIX32(4L)
#define JUMP_SPEED_MAX      FIX32(22L)
#define JUMP_SPEED_DEFAULT  FIX32(7.8L)

#define GRAVITY_MIN         FIX32(0.15)
#define GRAVITY_MAX         FIX32(0.8)
#define GRAVITY_DEFAULT     FIX32(0.36)//0.32

typedef struct
{
        Sprite *sprite;
        fix32 pos_x;
        fix32 pos_y;
        fix32 vel_x;
        fix32 vel_y;

        s16 hitbox_x1;
        s16 hitbox_y1;
        s16 hitbox_x2;
        s16 hitbox_y2;

        bool active;
        u16 ticks;
        u16 hitpoints;
} CP_SPRITE;
//Entity player = {0, 0, 16, 16, 0, 0, 0, NULL, "PLAYER" };

// physic settings
extern fix32 maxSpeed;
extern fix32 jumpSpeed;
extern fix32 gravity;

// player position
fix32 posX; //extern
 fix32 posY;
 fix32 movX;
s16 xOrder;
s16 yOrder;
 int isAttacking;
 int A_Bpressed;
 //int Sguage = 100;
 //CP_SPRITE player;
Sprite* player;
BoxCollision* PLAYER_box;
u16 PLAYER_init(u16 vramIndex);

void PLAYER_update(void);
void PLAYER_updateScreenPosition(void);
void PLAYER_special();
void PLAYER_handleInput(u16 value);
void PLAYER_doJoyAction(u16 joy, u16 changed, u16 state);
void PLAYER_action(u32 ticks,int arr[]);

#endif // _PLAYER_H_
