#include "UI.h"
#include "battleshipsBoard.h"
#include "inp_val7.h"

void UI::printBoard(battleshipsBoard& bboard) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "  A B C D E F G H I J" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << i;
		for (int j = 0; j < 10; j++)
			if (bboard.board[i][j] == shipBody) {
				SetConsoleTextAttribute(hConsole, 127);
				std::cout << "[]";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
				std::cout << "[]";
		std::cout << std::endl;
	}
}

void UI::setBoard(battleshipsBoard& bboard) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			bboard.board[i][j] = empty;//set all to empty
	for (int Xbodies = 4; Xbodies > 0; Xbodies--)
		for (int Xships = 5 - Xbodies; Xships > 0; Xships--) {
			system("cls");
			UI::printBoard(bboard);
			UI::setShip(bboard, Xbodies);
		}
}

void UI::setShip(battleshipsBoard& bboard, int Xbodies) {
	point start;
	direction dir = horizontal;//for 1body
	bool gen = true;
	do {
		std::cout << "placing " << Xbodies << "-body ship" << std::endl;
		std::cout << "input coordinates of start of the ship(use correct start because direction can be only right/down)" << std::endl;
		start.x = cinum("input row:", "wrong input, try again", 1, 1, 0, 9);

		char y;
		std::cout << "input column: ";
		std::cin >> y;
		while (!((y >= 'A' && y <= 'J') || (y >= 'a' && y <= 'j')) || (std::cin.peek() != '\n')) {//until correct input
			while (std::cin.get() != '\n');//clear istream
			std::cout << "wrong input, try again." << std::endl;
			std::cout << "input column: ";
			std::cin >> y;
		}
		//std::cin.get();//enter
		start.y = toupper(y) - 65;//map(map(y, A_J, a_j), A_J, 0_9)

		if (Xbodies != 1) {//dont ask if 1body
			bool dirInt;
			dirInt = cinum("input direction(0 - right, 1 - down):", "wrong input, try again.", 1, 1, 0, 1);
			dir = static_cast<direction>(dirInt);
		}
		gen = bboard.validateShip(start, dir, Xbodies);
		if (!gen)
			std::cout << "wrong input, try again" << std::endl;
	} while (!gen);
	bboard.placeShip(start, dir, Xbodies);
}

void UI::menu(battleshipsBoard& bboard) {
	bool boardExists = false;//let !exists on first turn
	int menuChoice;
	do {
		system("cls");
		if (boardExists) {
			UI::printBoard(bboard);
		}
		std::cout << "1. Generate board." << std::endl;
		if(boardExists)
			std::cout << "2. Save this board to file." << std::endl;
		std::cout << "3. Load board from file." << std::endl;
		std::cout << "4. Set the board." << std::endl;
		std::cout << "5. Exit." << std::endl;
		menuChoice = cinum("Choose what to do:", "Wrong input, try again", 1, 1, 1, 5);

		switch (menuChoice) {
		case 1:
			bboard.genBoard();
			boardExists = true;
			break;
		case 2:
			if (boardExists) {
				std::ofstream binarySave;
				char fileOutName[256];
				errno_t err = tmpnam_s(fileOutName, 255);
				binarySave.open(fileOutName, std::ofstream::binary);
				fileHandle::writeBoard(bboard, binarySave);
				std::cout << "board is saved in " << fileOutName << " file" << std::endl;
				system("pause");
			}
			break;
		case 3: {
			std::ifstream binarySave;
			char fileInName[256];
			do {
				std::fill_n(fileInName, 256, 0);//0 = '\0'
				std::cout << "input address of file(or only name if it is in the same folder as programm) starting with disk:\\ and ending with *.txt: " << std::endl;
				std::cin.get();//enter
				std::cin.getline(fileInName, 255);
				binarySave.open(fileInName, std::ifstream::binary);
				if (!binarySave.is_open())
					std::cout << "Can't open that file!" << std::endl;
			} while (!binarySave.is_open());
			fileHandle::readBoard(bboard, binarySave);
			boardExists = true;
			break;
		}
		case 4:
			UI::setBoard(bboard);
			boardExists = true;
			break;
		}
	} while (menuChoice != 5);
}