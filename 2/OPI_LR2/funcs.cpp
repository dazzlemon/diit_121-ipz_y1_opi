// struct of void** arguments:
// args[0] is TYPE
// args[1]-args[3] is coordinates in following order: a, b, c; or x, m, n; or a, m, n
// args[4] is result box

#include "funcs.h"
#include <iostream>

bool func1(void** args) {
	TYPE type = *reinterpret_cast<TYPE*>(args[0]);
	double a, b, c;
	switch (type) {
	case int_:
		a = *static_cast<int*>(args[1]);
		b = *static_cast<int*>(args[2]);
		c = *static_cast<int*>(args[3]);
		break;
	case double_:
		a = *static_cast<double*>(args[1]);
		b = *static_cast<double*>(args[2]);
		c = *static_cast<double*>(args[3]);
		break;
	}
	bool goodbit = false;
	if ((b != 0) && (a * b != -1) && (c != 0) && (a * b * c + a + c != 0) && (c != -1 / b) && (c != -1 / (a * b + 1)) && (b * c != -1)) {
		switch (type) {
		case int_:
			*(static_cast<int*>(args[4])) = -1;
			break;
		case double_:
			*(static_cast<double*>(args[4])) = -1;
			break;
		}
		goodbit = true;
	}
	return goodbit;
}

bool func2(void** args) {
	TYPE type = *reinterpret_cast<TYPE*>(args[0]);
	double x, m, n;
	switch (type) {
	case int_:
		x = *static_cast<int*>(args[1]);
		m = *static_cast<int*>(args[2]);
		n = *static_cast<int*>(args[3]);
		break;
	case double_:
		x = *static_cast<double*>(args[1]);
		m = *static_cast<double*>(args[2]);
		n = *static_cast<double*>(args[3]);
		break;
	}
	bool goodbit = false;
	if (x > 0 && m != 0 && n != 0) {
		double result = (pow(x, 1 / m) + 3 * pow(x, 1 / n)) / x;
		switch (type) {
		case int_:
			*(static_cast<int*>(args[4])) = result;
			break;
		case double_:
			*(static_cast<double*>(args[4])) = result;
			break;
		}
		goodbit = true;
	}
	return goodbit;
}

bool func3(void** args) {
	TYPE type = *reinterpret_cast<TYPE*>(args[0]);
	double a, m, n;
	switch (type) {
	case int_:
		a = *static_cast<int*>(args[1]);
		m = *static_cast<int*>(args[2]);
		n = *static_cast<int*>(args[3]);
		break;
	case double_:
		a = *static_cast<double*>(args[1]);
		m = *static_cast<double*>(args[2]);
		n = *static_cast<double*>(args[3]);
		break;
	}
	bool goodbit = false;
	if (a > 0 && m != 0 && n != 0) {
		double result = 4 * pow(a, (m + n) / (m * n)) * (pow(a, 1 / m) - pow(a, 1 / n));
		result /= (pow(a, 1 / m) + pow(a, 1 / n)) * pow(pow(a, m + 1) + pow(a, (n + 1) / n), 1 / m);
		switch (type) {
		case int_:
			*(static_cast<int*>(args[4])) = result;
			break;
		case double_:
			*(static_cast<double*>(args[4])) = result;
			break;
		}
		goodbit = true;
	}
	return goodbit;
}

TYPE chooseType() {
	TYPE type_;
	std::cout << "1. int" << std::endl;
	std::cout << "2. double" << std::endl;
	type_ = static_cast<TYPE>(cinum("choose type to which result and args are casted: ", "Wrong input, try again", 1, 1, 1, 2) - 1);

	return type_;
}