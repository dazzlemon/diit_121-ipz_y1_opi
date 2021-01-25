#include "fileHandle.h"
#include "battleshipsBoard.h"

void fileHandle::readBoard(battleshipsBoard& bboard, std::ifstream& file) {
	seaField temp[100];
	file.read(reinterpret_cast<char*>(temp), sizeof(temp));
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			bboard.board[i][j] = static_cast<seaField>(temp[i * 10 + j]);
}

void fileHandle::writeBoard(battleshipsBoard& bboard, std::ofstream& file) {
	seaField temp[100];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			temp[i * 10 + j] = bboard.board[i][j];
	file.write(reinterpret_cast<char*>(temp), sizeof(temp));
}