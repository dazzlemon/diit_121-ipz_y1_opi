#ifndef __BATTLESHIPS_H__
#define __BATTLESHIPS_H__

#include <random>
#include <chrono>
#include <iostream>
#include <Windows.h>

enum seaField { empty, shipBody, bodyHit, miss, shipNeighbour };
enum direction { horizontal, vertical };
struct point {
	int x;
	int y;
};

struct battleshipsBoard {
	battleshipsBoard();
	~battleshipsBoard();

	seaField** board;

	//checks if given ship can be placed in this object
	bool validateShip(point start, direction dir, int length);
	//places ship(use validation before!)
	void placeShip(point start, direction dir, int length);
	//generates board
	void genBoard();
	//generates, checks and places x-body ship in this object
	void genXbody(int Xbodies);
	//prints this object
	void printBoard();
};

#endif