#include "UI.h"

void UI::printBoard(battleshipsBoard &board_) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "  A B C D E F G H I J" << std::endl;
	point XY;
	for (XY.x = 0; XY.x < 10; XY.x++) {
		std::cout << XY.x;
		for (XY.y = 0; XY.y < 10; XY.y++)
			if (board_.getCell(XY) == shipBody) {
				SetConsoleTextAttribute(hConsole, 127);
				std::cout << "[]";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
				std::cout << "[]";
		std::cout << std::endl;
	}
}

void UI::printTwoBoards(battleshipsBoard& board1, battleshipsBoard& board2) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "  A B C D E F G H I J" << "    " << "  A B C D E F G H I J" << std::endl;
	point XY;
	for (XY.x = 0; XY.x < 10; XY.x++) {//myBoard
		std::cout << XY.x;
		for (XY.y = 0; XY.y < 10; XY.y++)
			if (board1.getCell(XY) == shipBody) {
				SetConsoleTextAttribute(hConsole, 127);
				std::cout << "[]";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
				std::cout << "[]";

		std::cout << "    " << XY.x;//enemyBoard
		for (XY.y = 0; XY.y < 10; XY.y++)
			if (board2.getCell(XY) == shipBody) {//bodyHit, miss, etc
				SetConsoleTextAttribute(hConsole, 127);
				std::cout << "[]";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
				std::cout << "[]";
		std::cout << std::endl;
	}
	std::cout << "your board           " << "    " << "enemy board          " << std::endl;
}

point UI::getTurn(battleshipsBoard& enemyBoard) {//get turn with xy != already shot
	point XY{0, 0};

	std::cout << "which cell do you want to attack next?" << std::endl;
	std::cout << "input row(0-9): ";
	//std::cin >> row;
	std::cout << "input column(A-J): ";
	//std::cin >> column;
	system("pause");//tmp

	return XY;
}