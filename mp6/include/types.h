typedef signed char s8;
typedef signed short int s16;
typedef signed long s32;
typedef signed long long int s64;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef double f64;

typedef volatile f32 vf32;
typedef volatile f64 vf64;

#define GW_PLAYER_MAX 4

typedef struct GwPlayer_s {
/* 0x00 */ char unk_00[0x1C];
/* 0x1C */ s16 coin;
/* 0x1E */ char unk_1E[0x12];
/* 0x30 */ s16 star;
/* 0x32 */ char unk_32[0xD6];
} GWPLAYER; //sizeof 0x108

typedef struct GwSystem_s {
/* 0x00 */ char unk_00[4];
/* 0x04 */ u8 turnNo;
/* 0x05 */ u8 turnMax;
} GWSYSTEM;

extern GWSYSTEM GwSystem;

extern GWPLAYER GwPlayer[GW_PLAYER_MAX];