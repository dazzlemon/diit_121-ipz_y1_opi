#include "solution.h"
#include <iostream>
#include "matrix.h"

bool getBinaryAnswer(const char* question, const char* error) {
	char choice;
	std::cout << question;
	std::cin >> choice;
	bool ret;
	while ((choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') || (std::cin.peek() != '\n')) {//until correct input
		while (std::cin.get() != '\n');//clear istream
		std::cout << error << std::endl;
		std::cout << question;
		std::cin >> choice;
	}
	if (choice == 'N' || choice == 'n')
		ret = false;
	else//Y or y
		ret = true;
	return ret;
}

void solveOPI5() {
	std::cout << "You opened an app that showswork of Q&A dialogue." << std::endl;
	std::cout << "This application lets user create/generate matrix of any size he wants, change values of elements in the matrix" << std::endl;
	std::cout << "And executes following actions: checks every column for elements with duplicate digits." << std::endl;
	std::cout << "If it has any - sorts the column, else flips it." << std::endl;
	bool exit_ = !getBinaryAnswer("Would you like to continue? (Y/N)", "wrong input, try again.");

	int rowsAmount, columnsAmount;
	double** matrix2d = NULL;
	if (!exit_) {
		rowsAmount = inputNum(1, 32767, "Enter amount of rows: ");
		columnsAmount = inputNum(1, 32767, "Enter amount of columns: ");
		matrix2d = createMatrix<double>(rowsAmount, columnsAmount);
		if (getBinaryAnswer("Would you like to input matrix yourself? (Y/N)", "wrong input, try again.")) {
			setMatrix0(matrix2d, rowsAmount, columnsAmount);
			setMatrix(matrix2d, rowsAmount, columnsAmount);
		}
		else if (!(exit_ = !getBinaryAnswer("Would you like to generate matrix? (Y/N)", "wrong input, try again."))) {
			genMatrix(matrix2d, rowsAmount, columnsAmount);
			printMatrix(matrix2d, rowsAmount, columnsAmount);
		}
	}
	if (!exit_)
		exit_ = !getBinaryAnswer("Would like to calculate the result? (Y/N)", "wrong input, try again.");
	if (!exit_) {
		exercise(matrix2d, rowsAmount, columnsAmount);
		if (exit_ = getBinaryAnswer("Would like to print the result in console? (Y/N)", "wrong input, try again."))
			printMatrix(matrix2d, rowsAmount, columnsAmount);
	}
}