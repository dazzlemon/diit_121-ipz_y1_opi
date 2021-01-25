// struct of void** arguments:
// args[0] is TYPE
// args[1]-args[3] is coordinates in following order: a, b, c; or x, m, n; or a, m, n
// args[4] is result box
#ifndef __FUNCS_H__
#define __FUNCS_H__

#include "inp_val7.h"

typedef bool (*func)(void**);
enum TYPE {int_, double_};//make enum class?

bool func1(void** args);
bool func2(void** args);
bool func3(void** args);

TYPE chooseType();

#endif
