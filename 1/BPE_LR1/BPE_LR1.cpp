#include <iostream>
#include "matrix.h"
#include <stdexcept>
#include <windows.h>
#undef max
//#include <cmath>
#include <climits>
#include <sstream>
#include <string>

int main() {
	std::cout << "This application lets user create/generate matrix of any size he wants, change values of elements in the matrix." << std::endl;
	std::cout << "And executes next acts: checks every column if it has any elements with duplicate digits." << std::endl;
	std::cout << "If its true - sorts the column, else flips it." << std::endl << std::endl;
	
	int rowsAmount = inputNum(1, 32767, "Enter amount of rows: ");
	int columnsAmount = inputNum(1, 32767, "Enter amount of columns: ");

	char choice;
	std::cout << "Do you want to enter matrix yourself(if not - app will genreate it itself)?(Y/N)";
	std::cin >> choice;
	while ((choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') || (std::cin.peek() != '\n')) {//until correct input
		while (std::cin.get() != '\n');//clear istream
		std::cout << "wrong input, try again." << std::endl;
		std::cout << "Do you want to enter matrix yourself(if not - app will genreate it itself)?(Y/N)";
		std::cin >> choice;
	}

	double** matrix2d = createMatrix<double>(rowsAmount, columnsAmount);
	if (choice == 'N' || choice == 'n') {
		genMatrix(matrix2d, rowsAmount, columnsAmount);
		printMatrix(matrix2d, rowsAmount, columnsAmount);
	}
	else {
		setMatrix0(matrix2d, rowsAmount, columnsAmount);
		setMatrix(matrix2d, rowsAmount, columnsAmount);
	}
	std::cout << std::endl;

	exercise(matrix2d, rowsAmount, columnsAmount);
	printMatrix(matrix2d, rowsAmount, columnsAmount);
	deleteMatrix(matrix2d, rowsAmount, columnsAmount);

	system("pause");
	return 0;
}