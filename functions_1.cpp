#include "middle_str.h"

bool itc_isDigit(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

unsigned char itc_toUpper(unsigned char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return c;
}

unsigned char itc_changeCase(unsigned char c)
{
	if (c >= 'a' && c <= 'z')
		c = itc_toUpper(c);
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	return c;
}

bool  itc_compare(string str1, string str2)
{
	if (itc_len(str1) == itc_len(str2))
	{
		int _size = itc_len(str1);
		for (int i = 0; i < _size; i++)
		{
			if (str1[i] != str2[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

int itc_countWords(string str)
{
	str += " ";
	bool notSymbol = false;
	int cnt = 0;
	long long _size = itc_len(str);
	for (int i = 0; i < _size; i++)
	{
		if (str[i] == ' ')
		{
			if (!notSymbol)
				cnt++;
			notSymbol = false;
		}
		else
		{
			if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
				notSymbol = true;
		}
	}
	return cnt;
}
