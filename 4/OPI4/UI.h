#ifndef __UI_H__
#define __UI_H__

#include <iostream>
#include <Windows.h>
#include <fstream>
#include "inp_val7.h"

class battleshipsBoard;//in main or etc include UI then battleshipsBoard

class UI{
	static void setShip(battleshipsBoard& bboard, int Xbodies);//from user input
public:
	static void printBoard(battleshipsBoard& bboard);
	static void setBoard(battleshipsBoard& bboard);//from user inputs
	static void menu(battleshipsBoard& bboard);
};
#endif