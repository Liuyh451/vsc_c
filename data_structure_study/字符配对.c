#include <stdlib.h>
#include <string.h>
#include<stdio.h>
typedef int Position;
typedef struct SNode *PtrToSNode; 
struct SNode
{   char datas[200];
    Position top;
    int MaxSize;
};
typedef PtrToSNode Stack;
Stack initStack(int max){
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->top=-1;
    S->MaxSize=max;
    return S;
}
int isFull(Stack S){
    if(S->top==S->MaxSize-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(Stack S){
    if(S->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void  push(Stack S,char X){
    
        S->datas[++(S->top)]=X;
        
    
}
char pop(Stack S){
   
    return S->datas[S->top--];
}

void print(char ch) {  
    if(ch == '(') printf("(-?\n");  
    else if(ch == '[') printf("[-?\n");  
    else if(ch == '{') printf("{-?\n");  
    else if(ch == '<') printf("/*-?\n");  
}  

int main(){
    Stack S=initStack(200);
    char str[666];
    int f=1;
    while (1)
    {
        scanf("%s",str);
        if(str[0]=='.'&&str[1]==0){
            break;
        }
        int i;
        for(i=0;str[i];i++){
            if(f==0){
                break;
            }
            if(str[i]=='('||str[i]=='['||str[i]=='{'){
                push(S,str[i]);
            }
            else if(str[i]=='/'&&str[i+1]=='*'){
                push(S,'<');
                i++;
            }
            else if(str[i]==')'){
                if(!isEmpty(S)&&S->datas[S->top]=='('){
                    pop(S);
                }
                else{
                    printf("NO\n");
                    f=0;
                    if(isEmpty(S)==1){
                        printf("?-)\n");
                    }
                    else{
                        print(S->datas[S->top]);
                    }
                    break;
                }
            }
            else if(str[i]==']'){
                if(!isEmpty(S)&&S->datas[S->top]=='['){
                    pop(S);
                }
                else{
                    printf("NO\n");
                    f=0;
                    if(isEmpty(S)==1){
                        printf("?-]\n");
                    }
                    else{
                        print(S->datas[S->top]);
                    }
                    break;
                }
            }
            else if(str[i]=='}'){
                if(!isEmpty(S)&&S->datas[S->top]=='{'){
                    pop(S);
                }
                else{
                    printf("NO\n");
                    f=0;
                    if(isEmpty(S)==1){
                        printf("?-}\n");
                    }
                    else{
                        print(S->datas[S->top]);
                    }
                    break;
                }
            }
            else if(str[i]=='*'&&str[i+1]=='/'){
                i++;
                if(!isEmpty(S)&&S->datas[S->top]=='<'){
                    pop(S);
                }
                else{
                    printf("NO\n");
                    f=0;
                    if(isEmpty(S)==1){
                     }
                    else{
                        print(S->datas[S->top]);
                    }
                    break;
                }
            }
        }
    }
    if(f&&isEmpty(S)){
        printf("YES\n");
    }
    else if(f){
        printf("NO\n");
        print(S->datas[S->top]);
    }
    return 0;
}