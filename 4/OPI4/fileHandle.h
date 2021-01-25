#ifndef __FILEHANDLE_H__
#define __FILEHANDLE_H__

#include <fstream>

class battleshipsBoard;

class fileHandle{
public:
	static void readBoard(battleshipsBoard& bboard, std::ifstream& file);//binary
	static void writeBoard(battleshipsBoard& bboard, std::ofstream& file);//binary
};
#endif