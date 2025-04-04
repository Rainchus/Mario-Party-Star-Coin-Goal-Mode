/*
Here we create declarations for a few functions and variables in Mario Party 2 so they can be referenced from our C code.
Later we will tell armips their addresses by defining labels for them in mp2.asm.
*/
#include "types.h"
#include "OS.h"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

/* Buttons */

#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G	    0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001

/* Nintendo's official button names */

#define A_BUTTON	CONT_A
#define B_BUTTON	CONT_B
#define L_TRIG		CONT_L
#define R_TRIG		CONT_R
#define Z_TRIG		CONT_G
#define START_BUTTON	CONT_START
#define U_JPAD		CONT_UP
#define L_JPAD		CONT_LEFT
#define R_JPAD		CONT_RIGHT
#define D_JPAD		CONT_DOWN
#define U_CBUTTONS	CONT_E
#define L_CBUTTONS	CONT_C
#define R_CBUTTONS	CONT_F
#define D_CBUTTONS	CONT_D

typedef struct SpaceData {
/* 0x00 */ s8 unk_00;
/* 0x01 */ u8 space_type; // enum board_space_type
/* 0x02 */ s16 unk_02;
/* 0x04 */ s32 unk_04;
/* 0x08 */ f32 x;
/* 0x0C */ f32 y;
/* 0x10 */ f32 z;
/* 0x14 */ f32 sx;
/* 0x18 */ f32 sy;
/* 0x1C*/  f32 sz;
/* 0x20 */ void* event_list;
} SpaceData;

typedef struct GwPlayer_s {
    /* 0x00 */ u8 group;
    /* 0x01 */ u8 cpu_difficulty;
    /* 0x02 */ u8 pad;
    /* 0x03 */ u8 chr;
    /* 0x04 */ u8 stat;
    /* 0x05 */ char unk_05;
    /* 0x06 */ s16 gameCoin;
    /* 0x08 */ s16 bonusCoin;
    /* 0x0A */ s16 coin;
    /* 0x0C */ s16 checkCoin;
    /* 0x0E */ s8 star;
    /* 0x0F */ s8 clink;
    /* 0x10 */ s8 cidx;
    /* 0x11 */ s8 nlink;
    /* 0x12 */ s8 nidx;
    /* 0x13 */ s8 nnlink;
    /* 0x14 */ s8 nnidx;
    /* 0x15 */ s8 blink; //b link
    /* 0x16 */ s8 bidx;
    /* 0x17 */ u8 rev; //related to reverse mushroom flags
    /* 0x18 */ s8 itemNo[3];
    /* 0x1B */ s8 itemTurn;
    /* 0x1C */ u8 color;
    /* 0x1D */ u8 turn;
    /* 0x1E */ char unk_1E[2]; //likely padding
    /* 0x20 */ void* unk_20;
    /* 0x24 */ void* player_obj;
    /* 0x28 */ s16 gamePrize; //minigame star
    /* 0x2A */ s16 coinPrize; //coin star
    /* 0x2C */ s8 hatenaPrize; //happening space star
    /* 0x2D */ s8 redPrize;
    /* 0x2E */ s8 bluePrize;
    /* 0x2F */ s8 eventPrize;
    /* 0x30 */ s8 kupaPrize;
    /* 0x31 */ s8 battlePrize;
    /* 0x32 */ s8 itemPrize;
    /* 0x33 */ s8 bankPrize;
    /* 0x34 */ s8 gamblePrize;
    /* 0x35 */ s8 duelNo;
    /* 0x36 */ char unk_36[2];
} GW_PLAYER; //sizeof 0x38;

typedef struct GW_SYSTEM {
    /* 0x00 - 800F93A8 */ s16 unk_00;
    /* 0x02 - 800F93AA */ s16 current_board_index;
    /* 0x04 - 800F93AC */ s16 current_game_length; // 00=Lite Play,01=Standard Play,02=Full Play,03=Custom Play
    /* 0x06 - 800F93AE */ s16 total_turns;
    /* 0x08 - 800F93B0 */ s16 current_turn;
    /* 0x0A - 800F93B2 */ s16 unk_0A;
    /* 0x0C - 800F93B4 */ s16 star_spawn_indices[7];
    /* 0x1A - 800F93C2 */ s16 unk_1A;
    /* 0x1C - 800F93C4 */ s16 unk_1C;
    /* 0x1E - 800F93C6 */ s16 current_player_index;
    /* 0x20 - 800F93C8 */ s16 unk_20;
    /* 0x22 - 800F93CA */ s16 curPlayerAbsSpaceIndex;
    /* 0x24 - 800F93CC */ char unk_24[4];
} GW_SYSTEM; //sizeof 0x28?

extern GW_PLAYER GWPlayer[4];
extern GW_SYSTEM GWSystem;
