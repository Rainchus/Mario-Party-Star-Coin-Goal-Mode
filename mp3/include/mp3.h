/*
Here we create declarations for a few functions and variables in Mario Party 3 so they can be referenced from our C code.
Later we will tell armips their addresses by defining labels for them in mp3.asm.
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

//{0, BLUE_MP3, 0, 925.0f, 679.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0, 0},

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
    /* 0x00 - 800CD058 */ s8 playMode; //0x01 - Lite Play pause screen, 0x04 - Story Play pause screen
    /* 0x01 - 800CD059 */ s8 current_board_index;
    /* 0x02 - 800CD05A */ s8 total_turns;
    /* 0x03 - 800CD05B */ s8 current_turn;
    /* 0x04 - 800CD05C */ s8 current_game_length; // 00=Lite Play,01=Standard Play,02=Full Play,03=Custom Play
    /* 0x05 - 800CD05D */ s8 current_star_spawn; // Index of star space (index into star_spawn_indices)
    /* 0x06 - 800CD05E */ s8 star_spawn_indices[7];
    /* 0x0D - 800CD065 */ s8 unk_0D;
    /* 0x0E - 800CD066 */ s8 unk_0E;
    /* 0x0F - 800CD067 */ s8 current_player_index;
    /* 0x10 - 800CD068 */ s8 minigame_index;
    /* 0x11 - 800CD069 */ s8 current_space_index;
    /* 0x12 - 800CD06A */ s8 save_mode; //00 - Save every turn, 01 - Save this turn, 02 - Don't save
    /* 0x13 - 800CD06B */ s8 show_minigame_explanations; //00 - show, 01 - hide
    /* 0x14 - 800CD06C */ s8 message_speed; //00 - Fast, 01 - Normal, 02 - Slow
    /* 0x15 - 800CD06D */ s8 walk_speed; //00 - Fast, 01 - Normal, 02 - Slow
    /* 0x16 - 800CD06E */ s8 show_com_minigames; //00 - Show COM minigame, 01 - Hide COM minigame
    /* 0x17 - 800CD06F */ char unk_17[0x27]; //unknown
    union {
        /* 0x3E - 800CD096 */ s16 halfWordBytes[9]; //bytes related to storing information for each board
        /* 0x3E - 800CD096 */ s8 bytes[18]; //bytes related to storing information for each board
    } boardData;
    /* 0x50 - 800CD0A8 */ char unk_50[1];
    /* 0x51 - 800CD0A9 */ u8 cur_player_used_item; //1 if player already used an item this turn
    /* 0x52 - 800CD0AA */ s16 unk_52;
    /* 0x54 - 800CD0AC */ s16 unk_54;
    /* 0x56 - 800CD0AE */ s16 slow_dice_flags;
    /* 0x58 - 800CD0B0 */ s16 unk_58;
    /* 0x5A - 800CD0B2 */ s16 playerIndexVisitingBowser;
    /* 0x5C - 800CD0B4 */ u16 bank_coins;
    /* 0x5E - 800CD0B6 */ u8 data_flags[8]; //unknown what this is, unknown size
    /* 0x66 - 800CD0B8 */ u8 unk_66[0x3E];
} GW_SYSTEM; //sizeof 0xA4

extern GW_PLAYER GWPlayer[4];
extern GW_SYSTEM GWSystem;
