//中缀表达式转为后缀表达式
//适用于 +,-,*,/,(),的含数字或字母的表达式
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define maxsize 20
typedef struct SNode *Stack;
struct SNode
{
    char data[maxsize];
    int Top;
};
Stack createStack(Stack S)
{
    S = (Stack)malloc(sizeof(Stack));
    S->Top = -1;
    printf("create done\n");
    return S;
}
int isFull(Stack S)
{
    if (S->Top == maxsize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(Stack S)
{
    if (S->Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(Stack S, char X)
{
    if (isFull(S))
    {
        printf("Stack is Full\n");
    }
    else
    {
        S->Top++;
        S->data[S->Top] = X;
        //printf("push done\n");
        //S->data[++(S->Top)]=X;
    }
}
char Pop(Stack S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        if (S->data[S->Top] != '(')
        {
            printf("%c", S->data[S->Top]);
        }
        S->Top--;
        return S->data[S->Top];
    }
}

int opcompare(char x)
{
    int y;
    if (x == '+' || x == '-')
    {
        y = 1;
    }
    if (x == '*' || x == '/')
    {
        y = 2;
    }
    if (x == '(')
    {
        y = 3;
    }
    return y;
}
int main()
{
    Stack S;
    S = createStack(S);
    char s[100];
    gets(s);
    int i = 0;
    while (s[i] != '\0')
    {
        if (isdigit(s[i])||isalpha(s[i]))//遍历字符串如果是运算数则直接输出
        {
            printf("%c", s[i]);
        }
        else
        {
            if (s[i] == ')')//如果是),则弹出栈顶元素，直到遇见左括号
                            //包括左括号在内。不输出括号
            {
                while (S->Top!=-1)
                {
                    Pop(S);
                    if(S->data[S->Top]=='('){
                        Pop(S);
                        break;
                    }
                }
            }
            else
            {   //如果栈内为空则直接进栈
                //如果栈顶元素为左括号则直接进栈（栈内左括号优先级最低）
                if (isEmpty(S) || S->data[S->Top] == '(')
                {
                    Push(S, s[i]);
                }
                else
                {   //比较优先级顺序，s[i]大于栈顶则进栈，小于则弹出栈顶元素
                    if (opcompare(s[i]) > opcompare(S->data[S->Top]))
                    {
                        Push(S, s[i]);
                    }
                    else
                    {   Pop(S);
                        Push(S,s[i]);
                    }
                }
            }
        }
        i++;
    }
    while (isEmpty(S) != 1)
    {
        Pop(S);
    }
    return 0;
}
