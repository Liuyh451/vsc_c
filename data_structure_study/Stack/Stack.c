#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef struct  SNode *Stack;
struct SNode
{
    int data[maxsize];
    int Top;
};
Stack createStack(Stack S){
    S=(Stack)malloc(sizeof(Stack));
    S->Top=-1;
    printf("create done\n");
    return S;
}
int isFull(Stack S){
    if(S->Top==maxsize-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(Stack S){
    if(S->Top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Push(Stack S,int X){
    if(isFull(S)){
        printf("Stack is Full\n");
    }
    else{
        S->Top++;
        S->data[S->Top]=X;
        printf("push done\n");
        //S->data[++(S->Top)]=X;
    }
}
void Pop(Stack S){
    if(isEmpty(S)){
        printf("Stack is Empty\n");
    }
    else{
        printf("The Top Data is:%d\n",S->data[S->Top]);
        S->Top--;
        printf("pop done\n");
    }
}
int main(){
    Stack S;
    S=createStack(S);
    for(int i=0;i<10;i++){
        Push(S,i);
    }
    printf("%d",isFull(S));
    return 0;
}


