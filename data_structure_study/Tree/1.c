#include <stdio.h>
//满二叉树，已知先序，求后序
void fun(int a[], int l, int r, int n)
{   int f=l;
    l++;
    int mid = (l + r) / 2;
    if (l != mid)
    {
        fun(a, l, mid, n);
    }
    else
    {
        printf("%d,", a[l]);
    }
    if (r - mid > 1)
    {
        fun(a, mid + 1, r, n);
    }
    else
    {
        printf("%d,", a[r]);
    }

    printf("%d,", a[f]);
    
}

int main()
{
    /*  Write C code in this online editor and run it. */
    int A[15] = { 0, 1, 3,7,8 ,4,9,10,2,5,11,12,6,13,14};
    fun(A,0,14,15);
    return 0;
}
