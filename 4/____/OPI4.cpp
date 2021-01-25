//
#include <iostream>
#include "UI.h"
#include "gameManager.h"

int main() {
    player player1, player2;
    player1.enemyBoard.clearField();
    player1.myBoard.genBoard();
    Sleep(250);//to prevent generating same field
    player2.myBoard.genBoard();

    gameManager::play(player1, player2);
    
    return 0;
}