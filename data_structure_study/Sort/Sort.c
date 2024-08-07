#include <stdio.h>


void insertSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = A[i];
        while (j >= 0 && temp < A[j])
        {
            /* code */
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}
void halfInsertSort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int temp = a[i];
        int l = 0, h = i - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (a[mid] > temp)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        //
        j = i - 1;
        while (j >= h + 1)
        {
            /* code */
            a[j + 1] = a[j];
            j--;
        }

        a[h + 1] = temp;
    }
}

void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int f = 0;
        for (j = n - 1; j > i; j--)
        {
            if (a[j] > a[j - 1])
            {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                f = 1;
            }
        }
        if (f == 0)
        {
            break;
        }
    }
}
void quickSort(int a[], int l, int h)
{
    int i = l, j = h;
    int t = a[l];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j && a[j] > t)
            {
                j--;
            }
            if (i < j)
            {
                a[i++] = a[j];
            }
            while (i < j && a[i] <= t)
            {
                i++;
            }
            if (i < j)
            {
                a[j--] = a[i];
            }
        }
        a[i] = t;
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, h);
    }
}
void selectSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}
void tribelSort(int a[], int n)
{
    int r, i = 0, j = n - 1;
    while (i < j)
    {
        while (a[i] == -1)
        {
            /* code */
            i++;
        }
        while (a[j] == 1)
        {
            j--;
        }
        if (a[i] == 1)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            j--;
        }
        else
        {
            r = i;
            while (a[r] != -1)
            {
                /* code */
                r++;
                if (r >= j)
                {
                    break;
                }
            }
            if (r < j)
            {
                int t = a[r];
                a[r] = a[i];
                a[i] = t;
               
            }
             i++;
        }
    }
}
int main()
{
    int a[5] = {1, 4, 8, 5, 2};
    int b[20] = {-1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0};;
    tribelSort(b, 20);

    // insertSort(a, 5);
    // BubbleSort(a,5);
    // halfInsertSort(a, 5);
    // quickSort(a, 0, 4);
    // selectSort(a, 5);
    for (int i = 0; i < 20; i++)
    {
        printf("%d,", b[i]);
    }

    return 0;
}