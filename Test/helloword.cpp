#include <iostream>
#include <algorithm>
#include <string>
#include <cmath> // 包含 abs 函数的头文件
using namespace std;
void reverseSentence(string str)
{
    int end = str.size() - 1;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            for (int j = i + 1; j <= end; j++)
            {
                cout << str[j];
                if (j == end)
                {
                    cout << ' ';
                }
            }
            end = i - 1;
        }
        if (i == 0)
        {
            for (int j = 0; j <= end; j++)
            {
                cout << str[j];
                if (j == end)
                {
                    cout << ' ';
                }
            }
        }
    }
}
class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::string reversed;
        int end = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
            {
                for (int j = i + 1; j <= end; ++j)
                {
                    reversed += s[j];
                    if (j == end)
                    {
                        reversed += ' ';
                    }
                }
                end = i - 1;
            }
            if(s[0]==' '){
                s.erase(0, 1);
            }
            if (i == 0&&s[0]!=' ')
            {   
                for (int j = 0; j <= end; ++j)
                {
                    reversed += s[j];
                }
            }
        }
        return reversed;
    }
};
int main()
{
    string s;
    while (getline(cin, s))
    {
        reverseSentence(s);
        cout << endl;
    }

    return 0;
}