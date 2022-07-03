#include <stdlib.h>
#include <stdio.h>
struct Line_List
{
    int data[10];
    int Last;
};
typedef struct Line_List *List;
//创建一个空列表
List makeEmppt()
{
    List L;
    L = (List)malloc(sizeof(struct Line_List));
    L->Last = -1;
    printf("done\n");
    return L;
}
//按元素寻找，返回下标
int Find(int X, List L)
{
    int i = 0;
    while (i <= L->Last && L->data[i] != X)
    {
        i++;
    }
    if (i > L->Last)
    {
        return -1;
    }
    else
    {
        return i;
    }
}
void insert(int X, int Y, List L)
{
    Y -= 1;
    if (Y < 0 || Y > L->Last + 1)
    {
        printf("error\n");
    }
    else
    {
        int j = L->Last;
        // 将Y后元素全部后移
        while (j >= Y)
        {
            L->data[j + 1] = L->data[j];
            j--;
        }
        //插入位置Y
        L->data[Y] = X;
        L->Last++;
        //printf("%d",L->Last);
    }
}
//按元素位置删除
void delete (List L, int X)
{
    int i;
    for (i = X - 1; i < L->Last; i++)
    {
        L->data[i] = L->data[i + 1];
    }
    L->Last--;
}
//按元素内容删除
void delete_v(List L, int X)
{
    int i = 0;
    while (i < L->Last && L->data[i] != X)
    {
        i++;
    }
    delete (L, i + 1);
}
void printList(List L)
{
    int j = 0;
    while (j <= L->Last)
    {
        printf("%d", L->data[j]);
        j++;
    }
}
int main()
{
    List L;
    L = makeEmppt();
    for (int i = 0; i < 10; i++)
    {
        insert(i, 1, L);
    }
    printf("%d\n", Find(6, L));
    delete_v(L, 3);
    printList(L);

    return 0;
}