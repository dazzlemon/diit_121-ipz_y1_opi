#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "battleshipsBoard.h"
#include "UI.h"

class player {
public:
	//player();
	//~player();
	battleshipsBoard myBoard;
	battleshipsBoard enemyBoard;
	ship* myShips;//array of all ships
	point attack();
	seaField getAttacked(point XY);//make it return value after attacked
	bool isAlive();//state(if all myShips are sunk -> dead, else -> alive)
	int shipIndexByXY(point XY);//-1 if none
};

class bot : player{

};

#endif