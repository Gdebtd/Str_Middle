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
	if (str1 == "")
		return -1;
	if (str1 != "" && str2 == "")
		return 0;
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

bool itc_isValidWord(string str)
{
	if (str == "")
		return false;
	int len = itc_len(str);
	bool brackets = false;
	if (str[0] == '(')
	{
		if (str[len - 1] != ')')
			return false;
		else
			brackets = true;
	}
	else if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))
		return false;
	if (!brackets)
	{
		if (!((str[len - 1] >= 'a' && str[len - 1] <= 'z') || (str[len - 1] >= 'A' && str[len - 1] <= 'Z')))
		{
			if (str[len - 1] == '.' || str[len - 1] == ',' || str[len - 1] == '?' || str[len - 1] == '!')
			{
				if (!((str[len - 2] >= 'a' && str[len - 2] <= 'z') || (str[len - 2] >= 'A' && str[len - 2] <= 'Z')))
					return false;
			}
			else
				return false;
		}
	}
	for (int i = 1; i < len - 1; i++)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
			return false;
	}
	return true;
}

int itc_sign_cnt(string str)
{
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
			cnt++;
	return cnt;
}

string itc_get_word(string str)
{
	string result = "";
	for (int i = 0; str[i] != '\0'; i++)
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			result += str[i];
	return result;
}
