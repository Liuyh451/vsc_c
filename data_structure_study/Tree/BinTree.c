//******二叉树、二叉搜索树、线索二叉树**********
#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
typedef struct BNode *BinTree; /* 指针变量的声明 */
struct BNode
{
    int data;
    BinTree Left, Right;
};
typedef struct SNode *Stack;
struct SNode
{
    BinTree data[maxsize];
    int Top;
};
typedef struct QNode *Queue;
struct QNode
{
    BinTree Data[maxsize];
    int front, rear;
};
///////////////////////////////////////////////////////////////////////////
///////////////////////队列的函数////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
Queue createQueue(Queue Q)
{
    Q = (Queue)malloc(sizeof(Queue));
    Q->front = -1;
    Q->rear = -1;
    // printf("create_done\n");
    return Q;
}
void AddQ(Queue Q, BinTree X)
{
    if ((Q->rear + 1) % maxsize == Q->front)
    { //+1是因为留出一个空位来解决空满不能分辨的
        printf("Q is full\n");
    }
    else
    {
        Q->rear = (Q->rear + 1) % maxsize;
        Q->Data[Q->rear] = X;
        // printf("AddQ_done\n");
    }
}
BinTree DeleteQ(Queue Q)
{
    if (Q->rear == Q->front)
    {
        printf("Q is empty\n");
    }
    else
    {
        Q->front = (Q->front + 1) % maxsize;
        // printf("DeleteQ_done\n");
        return Q->Data[Q->front];
    }
}
///////////////////////////////////////////////////////////////////////////
///////////////////////栈的函数////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
Stack createStack(Stack S)
{
    S = (Stack)malloc(sizeof(Stack));
    S->Top = -1;
    // printf("create done\n");
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

void Push(Stack S, BinTree X)
{
    if (isFull(S))
    {
        printf("Stack is Full\n");
    }
    else
    {
        S->Top++;
        S->data[S->Top] = X;
        // printf("push done\n");
        // S->data[++(S->Top)]=X;
    }
}
BinTree Pop(Stack S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        // printf("The Top Data is:%d\n",S->data[S->Top]);
        S->Top--;
        // printf("pop done\n");
        return S->data[S->Top + 1];
    }
}
///////////////////////////////////////////////////////////////////////////
///////////////////////树的函数////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//直接创建树
BinTree CreateBinTreeDirectly(BinTree T)
{
    T = (BinTree)malloc(sizeof(struct BNode));
    (T)->data = 1;
    (T)->Left = (BinTree)malloc(sizeof(struct BNode));
    (T)->Right = (BinTree)malloc(sizeof(struct BNode));
    (T)->Left->data = 2;
    (T)->Left->Left = (BinTree)malloc(sizeof(struct BNode));
    (T)->Left->Right = (BinTree)malloc(sizeof(struct BNode));
    (T)->Left->Right->data = 5;
    (T)->Left->Right->Left = NULL;
    (T)->Left->Right->Right = NULL;
    (T)->Right->data = 3;
    (T)->Right->Left = (BinTree)malloc(sizeof(struct BNode));
    (T)->Right->Left->data = 6;
    (T)->Right->Left->Left = NULL;
    (T)->Right->Left->Right = NULL;
    (T)->Right->Right = (BinTree)malloc(sizeof(struct BNode));
    (T)->Right->Right->data = 7;
    (T)->Right->Right->Left = NULL;
    (T)->Right->Right->Right = NULL;
    (T)->Left->Left->data = 4;
    (T)->Left->Left->Left = NULL;
    (T)->Left->Left->Right = NULL;
    printf("Tree!!!\n");
    return T;
}
void initBinTree(BinTree BT)
{
    BT = (BinTree)malloc(sizeof(struct BNode));
    BT->data=999;
    BT->Left = NULL;
    BT->Right = NULL;
    //return BT;
}
//先序遍历 中 左 右
void frontorder(BinTree BT)
{
    if (BT)
    {
        printf("%d", BT->data);
        frontorder(BT->Left);
        frontorder(BT->Right);
    }
}
//中序遍历 左 中 右
void midorder(BinTree BT)
{
    if (BT)
    {
        midorder(BT->Left);
        printf("%d", BT->data);
        midorder(BT->Right);
    }
}
//后序遍历  左 右 中
void postorder(BinTree BT)
{
    if (BT)
    {
        postorder(BT->Left);
        postorder(BT->Right);
        printf("%d", BT->data);
    }
}
int getHeight(BinTree BT) //利用递归求高度，可见ipad
{
    int HL, HR, max;
    if (BT != NULL)
    {
        HL = getHeight(BT->Left);
        HR = getHeight(BT->Right);
        if (HL >= HR)
        {
            return HL + 1;
        }
        else
        {
            return HR + 1;
        }
    }
    else
    {
        return 0;
    }
}
/*线索二叉树Threaded BinaryTree
BinTree final, this, Pre, T;
void visit(BinTree this)
{
    if (this == T)
    {
        final = this;//如果当前结点与目标结点相同，final就是当前结点
    }
    else
    {
        Pre = this;//不同，则令pre=当前结点
    }
}
void TBTmidorder(BinTree BT)
{
    if (BT)
    {
        TBTmidorder(BT->Left);
        visit(BT);
        TBTmidorder(BT->Right);
    }
}
*/
/*下面三个都是用栈来表示先序，中序，和后序遍历的，不再使用递归
基本思想 中序：遇到结点压栈，然后遍历左结点，左节点完事后弹出栈顶结点再遍历他
然后遍历右子树*/
void InorderTraver(BinTree BT)
{
    Stack S = createStack(S);
    BinTree T = BT;
    while (T || !isEmpty(S)) //如果T不为空，栈不为空
    {
        while (T)
        {
            Push(S, T);
            // printf("%d",T->data);放在这就是先序
            T = T->Left;
        }
        if (!isEmpty(S))
        {
            T = Pop(S);
            printf("%d", T->data); //放这就是中序
            T = T->Right;
            // printf("%d",T->data);放这就是后序
        }
    }
}
int travelnode(BinTree BT)
{
    if (BT == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + travelnode(BT->Left) + travelnode(BT->Right);
    }
}
BinTree createBinTree(char str[])
{ //根据前序序列创建二叉树
    BinTree T = (BinTree)malloc(sizeof(struct BNode));
    int i = 0;
    T->data = str[i];
    i++;
    T->Left = createBinTree(str);
    T->Right = createBinTree(str);
    return T;
}
/*层序遍历
基本思想 遇到结点，进队，然后出队，访问，左右儿子进队
*/
void travelBinTreelevel(BinTree BT)
{
    Queue Q;
    BinTree T;
    if (BT == NULL)
    {
        return;
    } //若是空树则直接返回
    Q = createQueue(Q);
    AddQ(Q, BT); //根节点入队
    while (Q->rear != Q->front)
    {
        T = DeleteQ(Q);
        printf("%d", T->data);
        if (T->Left)
        {
            AddQ(Q, T->Left);
        }
        if (T->Right)
        {
            AddQ(Q, T->Right);
        }
    }
}
/*二叉搜索树*/
BinTree BSTFind0(BinTree BT, int X) //非递归方式查找元素
{
    while (BT)
    {
        if (X > BT->data)
        {
            BT = BT->Right;
        }
        else if (X < BT->data)
        {
            BT = BT->Left;
        }
        else
        {
            return BT;
        }
    }
    return BT;
}
//递归方式查找二叉搜索树
BinTree BSTFind1(BinTree BT, int X)
{
    if (X > BT->data)
    {
        return BSTFind1(BT->Right, X);
    }
    else if (X < BT->data)
    {
        return BSTFind1(BT->Left, X);
    }
    else
    {
        return BT;
    }
}
//查找BST最小元素所在结点,也即是最左子树
BinTree BSTFindMin(BinTree BST)
{
    if (!BST)
        return NULL; //如果BST为空
    else if (!BST->Left)
        return BST;
    else
    {
        return BSTFindMin(BST->Left); //递归查找最左元素
    }
}
//查找BST最大元素所在结点,也即是最右子树
BinTree BSTFindMax(BinTree BST)
{
    if (!BST)
        return NULL; //如果BST为空
    else if (!BST->Right)
        return BST;
    else
    {
        return BSTFindMin(BST->Right); //递归查找最右元素
    }
}
/*非递归方式实现
BinTree BSTFindMax(BinTree BST){
    if(BST){
        while (BST->Right)
        {
            BST=BST->Right;
        }

    }
}
*/
//二叉搜索树的插入
BinTree BSTInsert(BinTree BST, int X)
{
    if (!BST)
    {
        BST = (BinTree)malloc(sizeof(struct BNode));
        BST->data = X;
        BST->Left = BST->Right = NULL;
        return BST;
    }
    else
    {
        if (X > BST->data)
        {
            BST->Right = BSTInsert(BST->Right, X);
        }
        else if (X < BST->data)
        {
            BST->Left = BSTInsert(BST->Left, X); //=左边的Left是用来记录是插到左还是右了！！！
        }
    }
    return BST;
}
int main()
{
    BinTree BT;
    BinTree T;
    BT=CreateBinTreeDirectly(BT);
    Queue Q;
    Q = createQueue(Q);
    AddQ(Q, BT); //根节点入队
    while (Q->rear != Q->front)
    {
        T = DeleteQ(Q);
        printf("%d", T->data);
        if (T->Left)
        {
            AddQ(Q, T->Left);
        }
        if (T->Right)
        {
            AddQ(Q, T->Right);
        }
    }
    
    //BT = CreateBiTree(BT);
    //printf("%d", getHeight(BT));
   
    return 0;
}