#include <iostream>
#include "battleships.h"

int main() {

    std::cout << "This application generates and prints board for the game \"battleships\"." << std::endl;
    bool exit_ = false;
    do {
        battleshipsBoard* board1 = new battleshipsBoard;
        board1->genBoard();
        board1->printBoard();
        delete board1;

        char chExit;
        std::cout << "Do you want to exit the programm(No means generate next board)?(Y/N): ";
        std::cin >> chExit;
        while ((chExit != 'Y' && chExit != 'y' && chExit != 'N' && chExit != 'n') || (std::cin.peek() != '\n')) {//until correct input
            while (std::cin.get() != '\n');//clear istream
            std::cout << "wrong input, try again." << std::endl;
            std::cout << "Do you want to exit the programm?(Y/N): ";
            std::cin >> chExit;
        }
        exit_ = (chExit == 'Y' || chExit == 'y');
        std::cin.get();//enter
        system("cls");
    } while (!exit_);

    system("pause");
    return 0;
}