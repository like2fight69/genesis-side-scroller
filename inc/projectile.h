#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_


#define MAX_SPEED_MAX       FIX32(20L)
#define MAX_SPEED_MIN       FIX32(1L)
#define MAX_SPEED_DEFAULT   FIX32(8L)

#define JUMP_SPEED_MIN      FIX32(4L)
#define JUMP_SPEED_MAX      FIX32(22L)
#define JUMP_SPEED_DEFAULT  FIX32(7.8L)

#define GRAVITY_MIN         FIX32(0.15)
#define GRAVITY_MAX         FIX32(0.8)
//#define GRAVITY_DEFAULT     FIX32(0.32)

//init projectile sprite


typedef struct projectile {
    //char *key;
   // extern fix32 maxSpeed;
   // struct projectile *next;
} proj;

Sprite* projectile;
BoxCollision* PROJ_box;
// physic settings
 extern fix32 maxSpeed;
//extern fix32 jumpSpeed;
//extern fix32 gravity;

// player position
//extern fix32 PROJ_posX;
fix32 PROJ_posX;
extern fix32 posX;
extern fix32 posY;
s16 xPos;
s16 yPos;

u16 PROJECTILE_init(u16 vramIndex);

//void PLAYER_update(void);
//void PLAYER_updateScreenPosition(void);

//void PLAYER_handleInput(u16 value);
//void PLAYER_doJoyAction(u16 joy, u16 changed, u16 state);


#endif // _PROJECTILE_H_
