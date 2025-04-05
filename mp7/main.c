
#include "include/types.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define _ASM_STRING(str_var, str_value, counter_val) \
    asm( \
        "bl  _end" TOSTRING(counter_val) "\n" \
        ".asciz \"" str_value "\"\n" \
        ".balign 4\n" \
        "_end" TOSTRING(counter_val) ":\n" \
        "mflr %0\n" \
        : "=r" (str_var) \
    );
    
#define ASM_STRING(str_var, str_value) _ASM_STRING(str_var, str_value, __COUNTER__)


#define _ASM_DATA(data_var, data_array, counter_val) \
    asm( \
        "bl  _end" TOSTRING(counter_val) "\n" \
        ".byte " data_array "\n" \
        ".balign 4\n" \
        "_end" TOSTRING(counter_val) ":\n" \
        "mflr %0\n" \
        : "=r" (data_var) \
    );


#define ASM_DATA(data_var, data_array) _ASM_DATA(data_var, data_array, __COUNTER__)

#define _ASM_DATA_s16(data_var, data_array, counter_val) \
    asm( \
        "bl  _end" TOSTRING(counter_val) "\n" \
        ".halfword " data_array "\n" \
        ".balign 4\n" \
        "_end" TOSTRING(counter_val) ":\n" \
        "mflr %0\n" \
        : "=r" (data_var) \
    );


#define ASM_DATA_s16(data_var, data_array) _ASM_DATA(data_var, data_array, __COUNTER__)

u32 frandmod(u32 arg0);
extern s32 lbl_802F2F3C;
extern s32 lbl_802F39F0;

//80178d10
void minigameListLoadHook(s32 minigameType, s32 arg1) {
    s32 i;
    s8* capsuleIDs;

    //-1 for pinkBooBandit

    //__ (used to only set this data for spaces once)
    if (_CheckFlag(0x10001) != 0) {
        return;
    }

    ASM_DATA(capsuleIDs, "0, 1, 2, 3, 10, 11, 12, 13, 14, 15, -1, 20, 21, 22, 23, 24, 25, 28");

    for (i = 0; i < ARRAY_COUNT(GwSystem.spaces); i++) {
        s8 randCapsule = capsuleIDs[frandmod(18)];
        //replace pink boo with bandit on windmillville
        if (randCapsule == -1) {
            if (lbl_802F2F3C == 0x7E) {
                randCapsule = 16; //bandit
            } else {
                randCapsule = 17; //pink boo
            }
            GwSystem.spaces[i].owner = -1;
        } else if (randCapsule == 28) { //koopa kid
            GwSystem.spaces[i].owner = 8; //set owner as koopa kid
        } else {
            GwSystem.spaces[i].owner = -1;
        }
        GwSystem.spaces[i].capsuleID = randCapsule;
    }
}