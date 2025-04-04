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

#define GW_STAT_LEN 52
#define GW_PLAYER_MAX 4

typedef struct GwPlayer_s {
    u16 dif : 2;
    u16 comF : 1;
    u16 charNo : 4;
    u16 field3 : 2;
    u16 deadF : 1;
    u16 saiMode : 6;
    u16 grp : 1;
    u16 storySkipEventF : 1;
    u16 playerNo : 2;
    s8 handicap;
    s8 padNo;
    s8 capsule[3];
    u16 color : 2;
    u16 moveF : 1;
    u16 jumpF : 1;
    u16 dispLightF : 1;
    u16 orderNo : 2;
    u16 diceCnt : 2;
    u16 rank : 2;
    s8 walkNum;
    s16 masuId;
    s16 masuIdPrev;
    s16 masuIdNext;
    s16 capsuleUse;
    s8 blueMasuNum;
    s8 redMasuNum;
    s8 capsuleMasuNum;
    s8 hatenaMasuNum;
    s8 kupaMasuNum;
    s8 m444MasuNum;
    s8 battleMasuNum;
    s8 kinokoMasuNum;
    s8 warpMasuNum;
    s8 starMasuNum;
    s8 donkeyMasuNum;
    s16 coin;
    s16 coinTotalMg;
    s16 coinTotal;
    s16 coinMax;
    s16 coinBattle;
    s16 mgCoin;
    s16 mgCoinBonus;
    s32 mgScore;
    s16 star;
    s16 starMax;
    s16 starStat[GW_STAT_LEN];
    s16 coinStat[GW_STAT_LEN];
} GWPLAYER;

typedef struct GwSystem_s {
    u8 partyF : 1;
    u8 teamF : 1;
    u8 storyDif;
    u16 bonusStarF : 1;
    u16 mgInstF : 1;
    u16 mgComF : 1;
    u16 mgPack : 3;
    u16 messSpeed : 2;
    u16 saveMode : 2;
    u8 turnNo;
    u8 turnMax;
    u8 starFlag;
    u8 starTotal;
    u8 starPos : 3;
    u8 boardNo : 5;
    s8 last5Effect;
    s8 turnPlayerNo;
    u8 unk[3];
    s16 saiMasuId;
    u32 mbSaveWork[8];
    u8 messDelay;
    u8 mgEvent : 4;
    s8 playerMode;
    u16 mgNo;
    s16 subGameNo;
    u16 bankCoin;
    s16 masuCapsule[256];
    u8 flag[8][16];
} GWSYSTEM;

extern GWSYSTEM GwSystem;

extern GWPLAYER GwPlayer[GW_PLAYER_MAX];