#include "middle_str.h"

string itc_dlin_slovo(string str)
{
    int max_cnt = 0;
    int cnt = 0;
    string str2 = "";
    string answer = ""
    long long _size = itc_len(str);
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
        }
        else
        {
            cnt++;
            str2 += str[i];
        }
    }
    return cnt;
}
