#include <stdio.h>
int main()
{
    int n, i = 0, a, b, c;
    scanf("%d", &n);
    while (i < n && scanf("%d%d%d", &a, &b, &c))
    {
        i++;
        if (a + b > c && a + c > b && b + c > a)
        {
            double cosA, cosB, cosC;
            cosA = (b * b + c * c - a * a) / (2 * c * b);
            cosB = (a * a + c * c - b * b) / (2 * c * a);
            cosC = (a * a + b * b - c * c) / (2 * b * a);
            if (cosA < 0.0 || cosB < 0.0 || cosC < 0.0)
            {
                printf("3");
                // 钝角三角形
            }
            else if (cosA == 0.0 || cosB == 0.0 || cosC == 0.0)
            {
                printf("2");
                // 直角三角形
            }
            else
            {
                printf("1");
                // 锐角三角形
            }
            printf("\n");
                }
        else
        {
            printf("-1");
        }
    }
    return 0;
}