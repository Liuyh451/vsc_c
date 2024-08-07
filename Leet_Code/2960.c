#include <stdlib.h>
#include <stdio.h>
int countTestedDevices(int *batteryPercentages, int batteryPercentagesSize)
{
    int sum = 0;
    for (int i = 0; i < batteryPercentagesSize; i++)
    {
        if (batteryPercentages[i] == 0)
        {
            continue;
        }
        else
        {
            sum++;
            for (int j = i + 1; j < batteryPercentagesSize; j++)
        {

            if (batteryPercentages[j] > 0)
            {
                batteryPercentages[j]--;
            }
        }
        }
    }
    return sum;
}

int main()
{
    int batteryPercentages[] = {0,1,2};
    int size=sizeof(batteryPercentages)/sizeof(batteryPercentages[0]);
    printf("%d", countTestedDevices(batteryPercentages, size));

    return 0;
}