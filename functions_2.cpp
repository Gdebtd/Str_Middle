#include "middle_str.h"

string itc_maxCharWord(string str)
{
	if (str == "")
		return "error";
	str += " ";
	string word = "", result = "";
	int cnt = 0, maxCnt = 0, wordsCnt = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (itc_isValidWord(word))
			{
				wordsCnt++;
				int signCnt = itc_sign_cnt(word);
				if (cnt - signCnt > maxCnt)
				{
					maxCnt = cnt - signCnt;
					result = itc_get_word(word);
				}
			}
			cnt = 0;
			word = "";
		}
		else
		{
			word += str[i];
			cnt++;
		}
	}
	if (wordsCnt == 0)
		return "error";
	return result;
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
	string _result = "";
	_result += str[0];
	for (int i = 1; str[i] != '\0'; i++)
	{
	if (!(str[i] == ' ' && str[i - 1] == ' '))
		_result += str[i];
	}
	string result = "";
	int len = itc_len(_result);
	if (_result[len - 1] == ' ')
		len--;
	for (int i = 0; i < len; i++)
		result += _result[i];
	return result;
}
