//孩子兄弟表示法
//https://blog.csdn.net/chdjj/article/details/28111643
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsiling; //分别看作左右指针
} CSNode, *CSTree;
typedef struct QNode
{
    CSTree a[20];
    int font;
    int rear;
} * Queue;

CSTree InitTree(CSTree T, int x)
{
    T = (CSTree)malloc(sizeof(struct CSNode));
    T->data = x;
    T->firstchild = T->nextsiling = NULL;
    printf("success!\n");
    return T;
}
Queue InitQueue(Queue Q)
{
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->font = Q->rear = 0;
    return Q;
}
void insert(Queue Q, CSTree T)
{
    Q->a[Q->rear] = T;
    Q->rear++;
    printf("insert done\n");
}
CSTree Pop(Queue Q)
{
    CSTree T;
    T = Q->a[Q->font];
    Q->font++;
    return T;
}
//先序遍历 参数：树 T
void PreOrder(CSTree T)
{
    if (T)
    {
        printf("%d\n", T->data);
        if (T->firstchild)
        {
            PreOrder(T->firstchild);
        }
        PreOrder(T->nextsiling);
    }
}
//后序遍历
void PostOrder(CSTree T)
{
    if (T != NULL)
    {
        if (T->firstchild)
        {
            PostOrder(T->firstchild);
        }
        PostOrder(T->nextsiling);
        printf("%d\n", T->data);
    }
}
void fun(CSTree T, Queue Q)
{
    if (T->nextsiling)
    {
        insert(Q, T->nextsiling);
        fun(T->nextsiling, Q);
    }
    
}
// 层序遍历
void LevelOrder(CSTree T, Queue Q)
{
    insert(Q, T);
    CSTree TT;
    while (Q->font != Q->rear)
    {
        TT = Pop(Q);
        printf("%d\n", TT->data);
        if (TT->firstchild)
        {
            insert(Q, TT->firstchild);
            fun(TT->firstchild, Q);
        }
        /*if (TT->firstchild->nextsiling)
        {
            fun(TT->firstchild, Q);这个地方是错的，我把fun这一行写到了92行
            如果长子为空，右边必定为空，所以这个地方不需要判断。
            如果判断会出现报错，比如一个子树下没有任何孩子，这时长子为空（null），而其他孩子不是
            null，是一片空白，在fun函数判断的时候会报错
        }*/
    }
    
}
int main()
{
    CSTree T;
    T = InitTree(T, 1);
    Queue Q=InitQueue(Q);
    T->firstchild = InitTree(T->firstchild, 2);
    T->firstchild->nextsiling = InitTree(T->firstchild->nextsiling, 3);
    //T->firstchild->firstchild->nextsiling=NULL;这一行不能加，因为长子不存在null，不能将null再指向其他地方
    T->firstchild->nextsiling->nextsiling = InitTree(T->firstchild->nextsiling->nextsiling, 4);
    //T->firstchild->nextsiling->nextsiling->firstchild->nextsiling=NULL;
    T->firstchild->firstchild = InitTree(T->firstchild->firstchild, 5);
    T->firstchild->firstchild->nextsiling = InitTree(T->firstchild->firstchild->nextsiling, 6);
    LevelOrder(T,Q);
    return 0;
}