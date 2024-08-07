#include <iostream>
#include <string>
#include <regex>
#include <algorithm> // 包含transform函数
#include <cctype>    // 包含tolower函数

using namespace std;
// 将字符串转换为小写形式
string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main()
{
    string input_str;
    getline(cin, input_str);
    // 将两个字符串转换为小写形式
    string lowerStr1 = toLower(input_str);

    string replaced_str = regex_replace(lowerStr1, regex("tantan"), "baibai");
    string result = replaced_str == lowerStr1 ? "not find" : replaced_str;
    cout << result << endl;
    return 0;
}