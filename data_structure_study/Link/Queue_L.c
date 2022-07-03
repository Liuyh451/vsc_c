#include <stdio.h>
#include <stdlib.h>
//循环队列，链式队列
typedef struct LNode *Link;
struct LNode //结点用来记录队列的元素
{
    int data;
    Link next;
};
//定义队列的头尾结构体！！！！切记Q在这里不是指针了，用.来访问成员变量
typedef struct QNode
{
    Link front;
    Link rear;
}Queue;
Queue InitQueue(Queue Q)
{
    Q.front =Q.rear = (Link)malloc(sizeof(struct LNode)); //建立头结点
    Q.front->next=NULL;
    printf("Qinit_done");
    return Q;
}
int IsEmpty(Queue Q)
{
    if (Q.front == Q.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Queue AddQ(Queue Q, int X)//王道书上C++有取地址符，所以不需要传回Q，这里必须传回
{
    Link newnode = (Link)malloc(sizeof(Link));
    newnode->data = X;
    newnode->next = NULL;
    Q.rear->next = newnode; //开始时front和rear同时指向头结点，这行代码是让头结点中的next指针指向下一个结点
    Q.rear = newnode;       //rear指向新结点
    printf("add_done\n");
    return Q;
}
Queue DeleteQ(Queue Q)
{
    if (Q.front == Q.rear)
    {
        printf("error_empty\n");
    }
    else
    {
        printf("%d", Q.front->next->data);
        Q.front->next = Q.front->next->next; //头结点不能丢
        if (Q.rear == Q.front->next)         //如果只有一个结点,删除后变空
        {
            Q.rear = Q.front;
        }
        free(Q.front->next);
        printf("delete_done\n");
    }
    return Q;
}
int main()
{
    Queue Q;
    Q=InitQueue(Q);
    printf("%d", IsEmpty(Q));
    Q=AddQ(Q,888);
    Q=DeleteQ(Q);
    printf("%d", IsEmpty(Q));
    return 0;
}