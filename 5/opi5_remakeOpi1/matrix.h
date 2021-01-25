#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <bitset>
#include <string>

//allocate memory for matrix
template<typename T>
T** createMatrix(int rowsAmount, int columnsAmount) {//allocate memory for matrix
	T** matrix2d = new T * [rowsAmount];
	for (int i = 0; i < rowsAmount; i++)
		matrix2d[i] = new T[columnsAmount];
	return matrix2d;
}

//free up the memory
template<typename T>
void deleteMatrix(T** matrix2d, int rowsAmount, int columnsAmount) {
	for (int i = 0; i < rowsAmount; i++)
		delete[]matrix2d[i];
	delete[]matrix2d;
}

//set random values for matrix
template<typename T>
void genMatrix(T** matrix2d, int rowsAmount, int columnsAmount) {
	typedef std::chrono::high_resolution_clock myclock;
	myclock::time_point beginning = myclock::now();
	std::uniform_int_distribution<int> valueDistribution(0, 100);
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();
	std::default_random_engine generator(seed);
	for (int i = 0; i < rowsAmount; i++)
		for (int j = 0; j < columnsAmount; j++)
			matrix2d[i][j] = valueDistribution(generator);
}

template<typename T>
void printMatrix(T** matrix2d, int rowsAmount, int columnsAmount) {
	std::cout << std::left;
	for (int i = 0; i < rowsAmount; i++) {
		for (int j = 0; j < columnsAmount; j++)
			std::cout << std::setw(12) << matrix2d[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::right;
}

//sorts column using insertion sort algorithm
template <typename T>
void sortColumn(T** matrix2d, int column, int rowsAmount) {
	for (int i = 1; i < rowsAmount; i++)
		if (matrix2d[i][column] < matrix2d[i - 1][column]) {//insertionSort
			T temp = matrix2d[i][column];
			int j = i - 1;
			for (j; (j >= 0) && (temp < matrix2d[j][column]); j--)
				matrix2d[j + 1][column] = matrix2d[j][column];//find position and shift to right elements between new and old position
			matrix2d[j + 1][column] = temp;
		}
}

template <typename T>
void flipColumn(T** matrix2d, int column, int rowsAmount) {
	for (int i = 0, j = rowsAmount - 1; i <= j; i++, j--) {
		T temp = matrix2d[i][column];
		matrix2d[i][column] = matrix2d[j][column];
		matrix2d[j][column] = temp;
	}
}

bool hasDuplicateDigits(int a) {
	bool retValue = false;
	a = abs(a);
	if (a > 999999999)//>10digits, at least one is duplicate
		retValue = true; 
	else if (a > 10) {//if >= 2digits
		std::bitset<10> digitsUsed;
		int currentDigit;
		do {
			currentDigit = a % 10;
			a = (a - currentDigit) / 10;
			if (digitsUsed[currentDigit])
				retValue = true;
			else
				digitsUsed[currentDigit] = true;
		} while (a > 0 && !retValue);
	}
	return retValue;
}

//checks if column has any elemnts with duplicate digits
template <typename T>
bool columnElementsDuplicateDigits(T** matrix2d, int column, int rowsAmount) {
	bool has = false;
	T currentElement;
	for (int i = 0; i < rowsAmount && !has; i++)//has = if matrix2d[i][column] has >= 2 same numerals
		has = hasDuplicateDigits(matrix2d[i][column]);
	return has;
}

//performs a check on every column and sorts it if it has any elements with duplicate digits, flips if not
template <typename T>
void exercise(T** matrix2d, int rowsAmount, int columnsAmount) {
	for (int i = 0; i < columnsAmount; i++)
		if (columnElementsDuplicateDigits(matrix2d, i, rowsAmount))
			sortColumn(matrix2d, i, rowsAmount);
		else
			flipColumn(matrix2d, i, rowsAmount);
}

int inputNum(int leftLim, int rightLim, std::string invitation) {
	std::string cinStr;//////////////////////////////////////////
	int num = leftLim - 1;
	size_t* pos = new size_t{ 0 };
	do {//input validation
		std::cout << invitation;
		std::cin >> cinStr;
		if (std::cin.peek() != '\n') {//if istream isn't empty
			while (std::cin.get() != '\n');//clear istream
			std::cout << "incorrect format" << std::endl;
		}
		else {
			*pos = 0;//clear old
			try {
				num = std::stoi(cinStr, pos);//convert input to INT format, set *pos value to length of used substring
			}
			catch (std::invalid_argument) {
				std::cout << "incorrect format" << std::endl;
				num = leftLim - 1;
			}
			catch (std::out_of_range) {
				std::cout << "out of range" << std::endl;
				num = leftLim - 1;
			}
			if (*pos != 0)
				if (*pos < cinStr.size()) {
					std::cout << "incorrect format" << std::endl;
					num = leftLim - 1;
				}
				else if (num < leftLim || num >= rightLim) {
					std::cout << "out of range" << std::endl;
					num = leftLim - 1;
				}
		}
	} while (num < leftLim || num >= rightLim);
	return num;
}

//lets user to chnge any elements by indexes
template <typename T>
void setMatrix(T** matrix2d, int rowsAmount, int columnsAmount) {
	system("cls");
	printMatrix(matrix2d, rowsAmount, columnsAmount);
	char choice;
	std::cout << "Do you want to enter any elements?(Y/N)";
	std::cin >> choice;
	while ((choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') || (std::cin.peek() != '\n')) {
		while (std::cin.get() != '\n');//clear istream
		std::cout << "wrong input, try again." << std::endl;
		std::cout << "Do you want to enter any elements?(Y/N)";
		std::cin >> choice;
	}
	while (choice != 'N' && choice != 'n') {
		int i = inputNum(0, rowsAmount, "enter row of element you want to change: ");
		int j = inputNum(0, columnsAmount, "enter column of element you want to change: ");
		std::string elementName = "A[" + std::to_string(i) + "][" + std::to_string(j) + "] = ";
		matrix2d[i][j] = inputNum(-32768, 32767, elementName);
		
		system("cls");
		printMatrix(matrix2d, rowsAmount, columnsAmount);

		std::cout << "Do you want to enter any elements?(Y/N)";
		std::cin >> choice;
		while ((choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') || (std::cin.peek() != '\n')) {
			while (std::cin.get() != '\n');//clear istream
			std::cout << "wrong input, try again." << std::endl;
			std::cout << "Do you want to enter any more elements?(Y/N)";
			std::cin >> choice;
		}
	} 
}

//set all elements to 0
template <typename T>
void setMatrix0(T** matrix2d, int rowsAmount, int columnsAmount) {
	for (int i = 0; i < rowsAmount; i++)
		for (int j = 0; j < columnsAmount; j++)
			matrix2d[i][j] = 0;
}
#endif