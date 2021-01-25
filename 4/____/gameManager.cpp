#include "gameManager.h"

void gameManager::play(player& player1, player& player2) {
	while (player1.isAlive() && player2.isAlive()) {
		system("cls");
		UI::printTwoBoards(player1.myBoard, player1.enemyBoard);
		player2.getAttacked(player1.attack());
		player1.getAttacked(player2.attack());
	}
}