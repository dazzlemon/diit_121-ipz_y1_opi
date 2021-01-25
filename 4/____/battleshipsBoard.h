#ifndef __BATTLESHIPSBOARD_H__
#define __BATTLESHIPSBOARD_H__

#include <random>
#include <chrono>

enum seaField { empty, shipBody, bodyHit, miss, shipNeighbour, sunk };
enum direction { horizontal, vertical };
struct point {
	int x;
	int y;
};

class battleshipsBoard {
private:
	seaField** board;

	//generates, checks and places x-body ship in this object
	void genXbody(int Xbodies);
public:
	battleshipsBoard();
	~battleshipsBoard();
	seaField getCell(point XY);
	void setCell(point XY, seaField value);
	//generates board
	void genBoard();
	//set all != shipBody cells to sea
	void prepareForGame();
	//set all cells to empty(sea)
	void clearField();
	//checks if given ship can be placed in this object
	bool validateShip(point start, direction dir, int length);
	//places ship(use validation before!)
	void placeShip(point start, direction dir, int length);
};

struct ship {
	point* body;//array of indexes to bodies
	bool isSunk();//state of ship(if all bodies are hit -> sunk, otherwise !sunk)
};

#endif