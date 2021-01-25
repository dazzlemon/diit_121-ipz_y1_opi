//cinum - numerical only (R)
//char msg_invite - your message for inviting user to input their number
//char msg_error - if error input occures
//int m_ - check if input is multiple of this number
//bool intFlag - =1(only integer input); =0(any input)
//double left - leftmost point in diapasone for input
//double right - rightmost point in diapasone for input

#include <iostream>
#include <windows.h>
#undef max
#include <cmath>
#include <climits>

int cinum(const char* msg_invite, const char* msg_error, int m_, bool intFlag, float left, float right);
//input to char array with lenght validation
void val_char_lenght(char array[], int ary_size);