
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

//8021e0f0
//manually change the `blr` at the end of this function to `li r25, 0`
void minigameListLoadHook(s32 minigameType, s32 arg1) {
    s32 i;
    s16 starCount = *(s16*)0x802F220C;
    s16 coinCount = *(s16*)0x802F220E;

    //if both of these are 0, player didn't initialize the values. Auto set to 5 stars, 0 coins to win
    if (starCount == 0 && coinCount == 0) {
        *(s16*)0x802F220C = 5;
        starCount = *(s16*)0x802F220C;
    }
 
    for (i = 0; i < 4; i++) {
        //if any of the players meets the star and coin requirement at end of current turn, end game
        if (GwPlayer[i].star >= starCount && GwPlayer[i].coin >= coinCount) {
            GwSystem.turnNo = GwSystem.turnMax + 1;
            return;
        }
    }
    //go back one turn to prevent game from ending
    if (GwSystem.turnNo == GwSystem.turnMax) {
        GwSystem.turnNo = GwSystem.turnMax - 1;
    }
    
    return;
}