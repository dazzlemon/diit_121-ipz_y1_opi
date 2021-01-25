#ifndef __SOLUTION_H__
#define __SOLUTION_H__

//asks <question>, if answer isnt (Y || y || N || n) asks again. if (Y || y) returns true. if (N || n) returns false.
bool getBinaryAnswer(const char* question, const char* error);
//same as OPI1, but using dialogue scenario
void solveOPI5();
#endif