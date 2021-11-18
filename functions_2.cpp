#include "middle_str.h"

string itc_maxCharWord(string str)
{
	str += " ";
	if (itc_countWords(str) == 1)
		return "error";
	int max_cnt = 0, cnt = 0, _size = itc_len(str);
	string str2 = "", answer = "";
	for (int i = 0; i < _size; i++)
	{
		if (str[i] == ' ')
		{
			if (cnt > max_cnt)
			{
				max_cnt = cnt;
				cnt = 0;
				answer = str2;
			}
			str2 = "";
		}
		else
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			{
				cnt++;
				str2 += str[i];
			}
		}
	}
	return answer;
}

char itc_sameChar(string str)
{
	str += " ";
	int _size = itc_len(str);
	char c = ' ';
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (str[i] == str[j] && i != j && (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
			{
				c = str[i];
				return c;
			}
		}
	}
	return c;
}

bool itc_isFirstInSecond(string s1, string s2)
{
	if (itc_find_str(s2, s1) == -1)
		return false;
	return true;
}

string itc_Cezar(string str, int k)
{
	string result = "";
	int _size = itc_len(str);
	for (int i = 0; i < _size; i++)
	{
		char c = ' ';
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] + k < 'a')
				c = str[i] + k + ('z' - 'a' + 1);
			else
				c = str[i] + k;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] + k < 'A')
				c = str[i] + k + ('Z' - 'A' + 1);
			else
				c = str[i] + k;
		}
		
		else
			c = str[i];
		result += c;
	}
	return result;
}

string itc_rmFreeSpace(string str)
{
	string result = "";
	int _size = itc_len(str);
	for (int i = 0; i < _size; i++)
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
			result += " ";
		if (str[i] != ' ')
		{
			result += str[i];
		}
	}
	return result;
}
