#include "middle_str.h"

string itc_maxCharWord(string str)
{
	if (str == "")
		return "error";
	str += " ";
	if (itc_countWords(str) <= 1)
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
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
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
	if (str == "")
		return '\0';
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
	if (str == "")
		return "";
	k = (k + 26) % 26;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
		str[i] = str[i] - 'a' + k;
		str[i] = str[i] % 26 + 'a';
	}
	else if (str[i] >= 'A' && str[i] <= 'Z')
	{
		str[i] = str[i] - 'A' + k;
		str[i] = str[i] % 26 + 'A';
		}
	}
	return str;
}

string itc_rmFreeSpace(string str)
{
	if (str == "")
		return "";
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
