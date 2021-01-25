#include "battleshipsBoard.h"

bool battleshipsBoard::validateShip(point start, direction dir, int length) {
	bool usable = true;
	if (dir == horizontal)
		for (int i = 0; i < length && usable; i++)
			if (start.y + i < 10)
				usable = (this->board[start.x][start.y + i] == empty);
			else
				usable = false;
	else//vertical
		for (int i = 0; i < length && usable; i++)
			if (start.x + i < 10)
				usable = (this->board[start.x + i][start.y] == empty);
			else
				usable = false;
	return usable;
}

void battleshipsBoard::placeShip(point start, direction dir, int length) {
	if (dir == horizontal) {
		for (int i = 0; i < length; i++)
			this->board[start.x][start.y + i] = shipBody;
		if (start.y - 1 >= 0)
			this->board[start.x][start.y - 1] = shipNeighbour;
		if (start.y + length < 10)
			this->board[start.x][start.y + length] = shipNeighbour;

		if (start.x - 1 >= 0) {
			for (int i = 0; i < length; i++)
				this->board[start.x - 1][start.y + i] = shipNeighbour;
			if (start.y - 1 >= 0)
				this->board[start.x - 1][start.y - 1] = shipNeighbour;
			if (start.y + length < 10)
				this->board[start.x - 1][start.y + length] = shipNeighbour;
		}
		if (start.x + 1 < 10) {
			for (int i = 0; i < length; i++)
				this->board[start.x + 1][start.y + i] = shipNeighbour;
			if (start.y - 1 >= 0)
				this->board[start.x + 1][start.y - 1] = shipNeighbour;
			if (start.y + length < 10)
				this->board[start.x + 1][start.y + length] = shipNeighbour;
		}

	}//
	else {//vertical
		for (int i = 0; i < length; i++)
			this->board[start.x + i][start.y] = shipBody;
		if (start.x - 1 >= 0)
			this->board[start.x - 1][start.y] = shipNeighbour;
		if (start.x + length < 10)
			this->board[start.x + length][start.y] = shipNeighbour;

		if (start.y - 1 >= 0) {
			for (int i = 0; i < length; i++)
				this->board[start.x + i][start.y - 1] = shipNeighbour;
			if (start.x - 1 >= 0)
				this->board[start.x - 1][start.y - 1] = shipNeighbour;
			if (start.x + length < 10)
				this->board[start.x + length][start.y - 1] = shipNeighbour;
		}
		if (start.y + 1 < 10) {
			for (int i = 0; i < length; i++)
				this->board[start.x + i][start.y + 1] = shipNeighbour;
			if (start.x - 1 >= 0)
				this->board[start.x - 1][start.y + 1] = shipNeighbour;
			if (start.x + length < 10)
				this->board[start.x + length][start.y + 1] = shipNeighbour;
		}
	}
}

void battleshipsBoard::genBoard() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			this->board[i][j] = empty;

	genXbody(4);
	for (int i = 0; i < 2; i++)
		genXbody(3);
	for (int i = 0; i < 3; i++)
		genXbody(2);
	for (int i = 0; i < 4; i++)
		genXbody(1);
}

void battleshipsBoard::genXbody(int Xbodies) {//Xbodies supposed to be 1-4
	std::uniform_int_distribution<int> XYdistribution(0, 9);
	std::uniform_int_distribution<int> directioDistribution(0, 1);
	std::default_random_engine generator(time(NULL));
	point start;
	direction dir;
	bool gen = true;
	do {
		start.x = XYdistribution(generator);
		start.y = XYdistribution(generator);
		dir = static_cast<direction>(directioDistribution(generator));
		gen = validateShip(start, dir, Xbodies);
	} while (!gen);
	placeShip(start, dir, Xbodies);
}

battleshipsBoard::battleshipsBoard() {
	this->board = new seaField * [10];
	for (int i = 0; i < 10; i++)
		board[i] = new seaField[10];
}
battleshipsBoard::~battleshipsBoard() {
	for (int i = 0; i < 10; i++)
		delete[]board[i];
	delete[]board;
}

seaField battleshipsBoard::getCell(point XY) {
	return this->board[XY.x][XY.y];
}

void battleshipsBoard::prepareForGame() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (this->board[i][j] != shipBody)
				this->board[i][j] = empty;
}

void battleshipsBoard::clearField() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
				this->board[i][j] = empty;
}