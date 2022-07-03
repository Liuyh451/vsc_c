#include<stdio.h>
#include<stdlib.h>
//循环队列
typedef struct QNode *Queue;
#define maxsize 20
struct QNode
{   int Data[maxsize];
    int front,rear;
};
Queue createQueue(Queue Q){
    Q=(Queue)malloc(sizeof(Queue));
    Q->front=-1;
    Q->rear=-1;
    printf("create_done\n");
    return Q;
}
void AddQ(Queue Q,int X){
    if((Q->rear+1)%maxsize==Q->front){//+1是因为留出一个空位来解决空满不能分辨的
        printf("Q is full\n");
    }
    else{
        Q->rear=(Q->rear+1)%maxsize;
        Q->Data[Q->rear]=X;
        printf("AddQ_done\n");
    }
}
int DeleteQ(Queue Q){
    if(Q->rear==Q->front){
        printf("Q is empty\n");
    }
    else{
        Q->front=(Q->front+1)%maxsize;
        printf("DeleteQ_done\n");
        return Q->Data[Q->front];
    }
}
int GetHead(Queue Q){
    if(Q->front==-1){
        return Q->Data[Q->front+1];
    }
    else{
        return Q->Data[Q->front%maxsize];
    }
    
}
int main(){
    Queue Q=createQueue(Q);
    AddQ(Q,999);
    printf("%d",GetHead(Q));
    return 0;
}