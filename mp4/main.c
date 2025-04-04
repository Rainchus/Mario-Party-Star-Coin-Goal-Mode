
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

//800A1B44
//manually change the `blr` at the end of this function to `li r31, 0`
void minigameListLoadHook(s32 minigameType, s32 arg1) {
    s32 i;
    s16 starCount = *(s16*)0x801D345C;
    s16 coinCount = *(s16*)0x801D345E;

    //if both of these are 0, player didn't initialize the values. Auto set to 5 stars, 0 coins to win
    if (starCount == 0 && coinCount == 0) {
        *(s16*)0x801D345C = 5;
        starCount = *(s16*)0x801D345C;
    }
 
    for (i = 0; i < 4; i++) {
        //if any of the players has a star, end the game at the end of the turn
        if (GWPlayer[i].stars >= starCount && GWPlayer[i].coins >= coinCount) {
            GWSystem.turn = GWSystem.max_turn;
            return;
        }
    }
    //go back one turn to prevent game from ending
    //mp4 doesn't increment the turn counter until starting the next turn -
    //unlike mp5 and mp6 which both increment the turn at the minigame wheel
    if (GWSystem.turn == GWSystem.max_turn - 1) {
        GWSystem.turn = GWSystem.max_turn - 2;
    }
    
    return;
}