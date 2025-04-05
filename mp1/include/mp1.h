/*
Here we create declarations for a few functions and variables in Mario Party 2 so they can be referenced from our C code.
Later we will tell armips their addresses by defining labels for them in mp1.asm.
*/
#include "types.h"
#include "OS.h"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

// /* Buttons */

// #define CONT_A      0x8000
// #define CONT_B      0x4000
// #define CONT_G	    0x2000
// #define CONT_START  0x1000
// #define CONT_UP     0x0800
// #define CONT_DOWN   0x0400
// #define CONT_LEFT   0x0200
// #define CONT_RIGHT  0x0100
// #define CONT_L      0x0020
// #define CONT_R      0x0010
// #define CONT_E      0x0008
// #define CONT_D      0x0004
// #define CONT_C      0x0002
// #define CONT_F      0x0001

// /* Nintendo's official button names */

// #define A_BUTTON	CONT_A
// #define B_BUTTON	CONT_B
// #define L_TRIG		CONT_L
// #define R_TRIG		CONT_R
// #define Z_TRIG		CONT_G
// #define START_BUTTON	CONT_START
// #define U_JPAD		CONT_UP
// #define L_JPAD		CONT_LEFT
// #define R_JPAD		CONT_RIGHT
// #define D_JPAD		CONT_DOWN
// #define U_CBUTTONS	CONT_E
// #define L_CBUTTONS	CONT_C
// #define R_CBUTTONS	CONT_F
// #define D_CBUTTONS	CONT_D

typedef struct GW_SYSTEM {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 curBoardIndex;
/* 0x04 */ s16 playType; //lite play, standard play, full play (20, 35, 50 turns)
/* 0x06 */ s16 total_turns;
/* 0x08 */ s16 current_turn;
/* 0x0A */ s16 chosenStarSpaceIndex;
/* 0x0C */ s16 starSpaces[7];
/* 0x1A */ s16 unk_1A;
/* 0x1C */ s16 current_player_index;
/* 0x1E */ s16 unk_1E;
/* 0x20 */ s16 curSpaceIndex;
/* 0x22 */ u8 saveSetting;
/* 0x23 */ s8 minigameExplanation;
/* 0x24 */ u8 messageSpeed;
/* 0x25 */ char unk_25;
} GW_SYSTEM; //sizeof 0x26

typedef struct GW_PLAYER {
/* 0x00 */ u8 group;
/* 0x01 */ u8 cpu_difficulty;
/* 0x02 */ u8 cpu_difficulty_copy;
/* 0x03 */ u8 port; //controller port
/* 0x04 */ u8 character;
/* 0x05 */ char unk_05; //likely padding
/* 0x06 */ u16 flags; // (flags) including CPU flag
/* 0x08 */ s16 coins; //player's current coins
/* 0x0A */ s16 coins_mg; //coins to give to player after minigame
/* 0x0C */ s16 stars;
/* 0x0E */ s16 cur_chain;
/* 0x10 */ u16 cur_space;
/* 0x12 */ u16 next_chain;
/* 0x14 */ u16 next_space;
/* 0x16 */ u8 poisoned_flag;
/* 0x17 */ u8 turn_status; //space type player landed on
/* 0x18 */ u8 player_index; //0, 1, 2, or 3
/* 0x19 */ char unk_19[3]; //likely padding
/* 0x1C */ void* process; //some heap instance
/* 0x20 */ void* player_obj; //ptr to player_obj on heap
/* 0x24 */ s16 coins_total; //how many coins a player has won/lost in minigames
/* 0x26 */ s16 coins_max; //highest amount of coins player has held
/* 0x28 */ u8 happening_count;
/* 0x29 */ u8 red_count;
/* 0x2A */ u8 blue_count;
/* 0x2B */ u8 minigame_count;
/* 0x2C */ u8 chance_count;
/* 0x2D */ u8 mushroom_count;
/* 0x2E */ u8 bowser_count;
/* 0x2F */ char unk_2F;
} GW_PLAYER; //sizeof 0x30
//P1 800F32B0, P2 800F32E0, P3 800F3310, P4 800F3340

extern GW_PLAYER GWPlayer[4];
extern GW_SYSTEM GWSystem;
