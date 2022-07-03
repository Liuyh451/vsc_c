//共享栈，又叫双堆栈
#include<stdlib.h>
#include<stdio.h>
#define maxsize 20
typedef struct  SNode *Stack;
struct SNode
{
    int data[maxsize];
    int Top1;
    int Top2;
};
Stack createStack(Stack S){
    S=(Stack)malloc(sizeof(Stack));
    S->Top1=-1;
    S->Top2=maxsize;
    printf("create done\n");
    return S;
}
int isFull(Stack S){
    if(S->Top2-S->Top1==1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(Stack S){
    if(S->Top1==-1){
        printf("S1 is empty\n");
        return 1;
    }
    else{
         if(S->Top2==maxsize){
        printf("S2 is empty\n");
        return 1;
    }
        else{
        return 0;
    }
    }
   

}
void Push(Stack S,int Tag,int X){
    if(isFull(S)){
        printf("error_full\n");
    }
    else{
        if(Tag==1){
            S->Top1++;
            S->data[S->Top1]=X;
        }
        else{
            S->Top2--;
            S->data[S->Top2]=X;
        }
        printf("push done\n");
    }
}
int Pop(Stack S, int Tag){
    if(Tag==1){
        if(S->Top1==-1){
            printf("error_S1_empty\n");
        }
        else{
            int X=S->data[S->Top1];
            S->Top1--;
            printf("top data is:%d\n",X);
            return X;
        }

    }
    else{ 
        if(S->Top2==maxsize){
            printf("error_S2_empty\n");
        }
        else{
            int X=S->data[S->Top2];
            S->Top2++;
            printf("top data is:%d\n",X);
            return X;
        }
    }
}
int main(){
    Stack S=createStack(S);
    Push(S,2,999);
    Pop(S,2);
    return 0;
}