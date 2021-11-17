#ifndef MIDDLE_STR_H_INCLUDED
#define MIDDLE_STR_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

bool itc_isDigit(unsigned char c);
unsigned char itc_toUpper(unsigned char c);
unsigned char itc_changeCase(unsigned char c);
bool  itc_compare(string str1, string str2);
int itc_countWords(string str);
//
int itc_len(string str);

#endif // MIDDLE_STR_H_INCLUDED
