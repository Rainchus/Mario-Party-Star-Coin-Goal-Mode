#include "../include/mp2.h"

extern s16 starAmountToEndGame;
extern s16 coinAmountToEndGame;

void checkGameEnd(void) {
    s32 i;

	//this is 0 when a turn ends and we want to run our code
	if (GWSystem.current_player_index != 0) {
		return;
	}

    //if both of these are 0, player didn't initialize the values. Auto set to 5 stars, 0 coins to win
    if (starAmountToEndGame == 0 && coinAmountToEndGame == 0) {
        starAmountToEndGame = 5;
    }
 
    for (i = 0; i < 4; i++) {
        //if any of the players meets the star/coin requirement, end the game
        if (GWPlayer[i].star >= starAmountToEndGame && GWPlayer[i].coin >= coinAmountToEndGame) {
            GWSystem.current_turn = GWSystem.total_turns;
            return;
        }
    }

    //go back one turn to prevent game from ending
    if (GWSystem.current_turn == GWSystem.total_turns - 1) {
        GWSystem.current_turn = GWSystem.total_turns - 2;
    }
}
