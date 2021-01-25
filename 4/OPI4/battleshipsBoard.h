#ifndef __BATTLESHIPSBOARD_H__
#define __BATTLESHIPSBOARD_H__

#include <random>
#include <chrono>
#include "UI.h"
#include "fileHandle.h"

enum seaField { empty, shipBody, bodyHit, miss, shipNeighbour };
enum direction { horizontal, vertical };
struct point {
	int x;
	int y;
};

class battleshipsBoard{
private:
	seaField** board;
	//generates, checks and places x-body ship in this object
	void genXbody(int Xbodies);
public:
	battleshipsBoard();
	~battleshipsBoard();

	//checks if given ship can be placed in this object
	bool validateShip(point start, direction dir, int length);
	//places ship(use validation before!)
	void placeShip(point start, direction dir, int length);
	//generates board
	void genBoard();

	friend class UI;
	friend class fileHandle;
};
#endif