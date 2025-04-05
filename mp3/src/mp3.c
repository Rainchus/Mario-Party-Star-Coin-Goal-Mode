#include "../include/mp3.h"

#define N64
#include "../../button_combo_exit.h"

extern s16 starAmountToEndGame;
extern s16 coinAmountToEndGame;
extern u16 ContBtn[];

void checkGameEnd(void) {
	//this is 0 when a turn ends and we want to run our code
	if (GWSystem.current_player_index != 0) {
		return;
	}

    if ((ContBtn[0] & BUTTON_COMBO_EXIT) == BUTTON_COMBO_EXIT) {
        GWSystem.current_turn = GWSystem.total_turns + 1;
        return;        
    }

    //go back one turn to prevent game from ending
    if (GWSystem.current_turn == GWSystem.total_turns) {
        GWSystem.current_turn = GWSystem.total_turns - 1;
    }
}
