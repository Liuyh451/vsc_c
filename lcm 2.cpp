#include <iostream>
#include <algorithm>
using namespace std;
// 辗转相除法求最大公约数
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int n;
    while (cin >> n)
    {
        int a[n], b;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b = i == 0 ? a[i] : lcm(a[i], b);
        }
        printf("%d\n", b);
    }
    return 0;
}