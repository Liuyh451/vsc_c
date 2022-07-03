#include <stdlib.h>
#include <stdio.h>
typedef struct Linked_List *List;
struct Linked_List
{
    int data;
    List next;
};

List createList(List L)
{
    L = (List)malloc(sizeof(List));
    L->next = NULL;
    L->data = NULL;
    printf("done\n");
    return L;
}
int Length(List L)
{
    List p = L; //让p指向L的第一个结点
    int j = 0;
    while (p) //全写是p!=null
    {
        p = p->next;
        j++;
    }
    return j;
}
//在表尾增加新结点
List AddNode(List L, int X)
{
    /*这种方法是错误的，因为使得L的头向前移动了
    导致再调用这个链表的时候，表头不对
    while(L->next){
        L=L->next;
    }*/
    List P = L; //要理解指针相等的含义，表面上是创建一个新指针，
                //其实是这两个指针一模一样，L只是为了记录表头
                //指针的作用就是告诉这个结点该去哪找下一个结点，所以哪个指针指都无所谓
    while (P->next)
    {
        P = P->next;
    }

    List newnode;
    newnode = (List)malloc(sizeof(List));
    newnode->data = X;
    newnode->next = NULL;
    P->next = newnode;
    printf("addnode_done\n");
    return L;
}
void printList(List L)
{
    while (L)
    {
        if (L->data == NULL)
        {
            L = L->next;
            continue;
        }
        printf("%d\n", L->data);
        L = L->next;
    }
}
//在位置X处插入结点
List insertnode(List L, int x, int y)
{
    //x=0表示在第一个元素之前插入
    if (x < 0)
    {
        printf("error");
    }
    if (x == 0)
    {
        List newhead = (List)malloc(sizeof(List));
        newhead->data = y;
        newhead->next = L;
        printf("insert_done_1");
        return newhead;
    }
    else
    {
        List T;
        List NewNode = (List)malloc(sizeof(List));
        int i = 1;
        T = L;
        while (i < x)
        {
            T = T->next;
            i++;
        }
        NewNode->data = y;
        NewNode->next = T->next;
        T->next = NewNode;
        printf("insert_done_2\n");
        return L;
    }
}
//在位置X处删除结点
List deleteList(List L, int x)
{
    List T, W;
    T = L;
    int i = 1;
    while (i < x)
    {
        T = T->next;
        i++;
    }
    T->next = T->next->next;
    /*W=T->next;
    T->next=W->next;
    free(W);
    */
    printf("delete_done\n");
    return L;
}
//查找元素，并返回下biao
int FindList(List L, int x)
{
    int cnt = 0;
    while (L && L->data != x)
    {
        L = L->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    List L;
    L = createList(L);
    for (int i = 0; i < 10; i++)
    {
        L = AddNode(L, i);
    }
    L = insertnode(L, 6, 999);
    printf("Length:%d\n", Length(L));
    deleteList(L, 2);
    printf("weizhi %d\n", FindList(L, 999));
    printList(L);
    return 0;
}
