#include "../include/mp1.h"

#define N64
#include "../../button_combo_exit.h"

extern s16 starAmountToEndGame;
extern s16 coinAmountToEndGame;
extern u16 ContBtn[];

void checkGameEnd(void) {
    if ((ContBtn[0] & BUTTON_COMBO_EXIT) == BUTTON_COMBO_EXIT) {
        GWSystem.current_turn = GWSystem.total_turns + 1;
        return;        
    }

    //go back one turn to prevent game from ending
    if (GWSystem.current_turn == GWSystem.total_turns - 1) {
        GWSystem.current_turn = GWSystem.total_turns - 2;
    }
}
