#include "middle_str.h"

int itc_len(string str)
{
	if (str == "")
		return 0;
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int itc_find_str(string str1, string str2)
{
	if (str1 == "" || str2 == "")
		return -1;
	int len2 = itc_len(str2), len = itc_len(str1);
	int i = 0, i2 = 0, index = -1;
	while (i < len)
	{
		if (str1[i] == str2[i2])
		{
			if (str1[i] == str2[0])
				index = i;
			i2++;
		}
		else
		{
			i2 = 0;
			index = -1;
		}
		i++;
		if (i2 > 0)
		{
			if (str2[i2 - 1] == str2[len2 - 1])
				return index;
		}
	}
	return -1;
}

string itc_rev_str(string str)
{
	if (str == "")
		return "";
	string result = "";
	int _size = itc_len(str);
	for (int i = _size - 1; i >= 0; i--)
		result += str[i];
	return result;
}
