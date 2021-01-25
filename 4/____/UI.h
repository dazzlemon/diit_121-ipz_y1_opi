#ifndef __UI_H__
#define __UI_H__

#include "battleshipsBoard.h"
//#include "player.h"
#include <iostream>
#include <Windows.h>

class UI {
public:
	//menu
	static point getTurn(battleshipsBoard& enemyBoard);//error because of looped include(UI->player->UI->player->.....to inf)
	static void printBoard(battleshipsBoard& board_);
	static void printTwoBoards(battleshipsBoard& board1, battleshipsBoard& board2);//horizontally aligned
};

#endif