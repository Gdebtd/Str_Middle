#include "middle_str.h"

bool itc_isIp(string str)
{
	if (str == "")
		return false;
	int _size = itc_len(str), zeroCnt = 0, num = 0;
	if (_size > 15 || _size < 7)
		return false;
	for (int i = 0; i < _size; i++)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return false;
		if (str[i] == '.')
			zeroCnt++;
	}
	if (zeroCnt != 3)
		return false;
	str += " ";
	for (int i = 0; i < _size + 1; i++)
	{
		if (str[i] == '.' || str[i] == ' ')
		{
			if (!(num >= 0 && num <= 255))
				return false;
			num = 0;
		}
		else
		{
			num *= 10;
			num += str[i] - '0';
		}
	}
	return true;
}

string itc_DecToBin(string str)
{
	string result = "";
	int _size = itc_len(str), num = 0;
	for (int i = 0; i < _size; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num *= 10;
			num += str[i] - '0';
		}
		else
		{
			if (i > 0 && str[i - 1] >= '0' && str[i - 1] <= '9')
			{
				result += itc_decToBase(num, 2);
				num = 0;
			}
			result += str[i];
		}
	}
	if (_size > 0 && str[_size - 1] >= '0' && str[_size - 1] <= '9')
		result += itc_decToBase(num, 2);
	return result;
}

string itc_decToBase(int num, int base)
{
	string result = "";
	string alp = "0123456789ABCDEF";
	if (num == 0)
		result = "0";
	while (num != 0)
	{
		result += alp[num % base];
		num /= base;
	}
	result = itc_rev_str(result);
	return result;
}

void itc_calculate_coordinates()
{
	int OX = 0, OY = 0;
	string str = "";
	int num = 0;
	while (str != "000")
	{
		cin >> str;
		if (str != "000")
			cin >> num;
		if (str == "North" || str == "South")
		{
			if (str == "South")
				num *= -1;
			OY += num;
		}
		else if (str == "East" || str == "West")
		{
			if (str == "West")
				num *= -1;
			OX += num;
		}
	}
	cout << OX << " " << OY;
}
