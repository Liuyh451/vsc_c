#include <iostream>
#include "Stack.h"
using namespace std;

// 定义二叉树的结点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 定义队列节点结构
struct QueueNode
{
    struct TreeNode *treeNode;
    struct QueueNode *next;
};

// 定义队列结构
struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};
// 入队操作
void enqueue(struct Queue *queue, struct TreeNode *treeNode)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队操作
struct TreeNode *dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        return NULL; // 队列为空
    }

    struct QueueNode *frontNode = queue->front;
    struct TreeNode *treeNode = frontNode->treeNode;

    queue->front = frontNode->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL; // 队列已空
    }

    free(frontNode);
    return treeNode;
}

// 层次遍历二叉树
void levelOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;

    enqueue(queue, root);

    while (queue->front != NULL)
    {
        struct TreeNode *current = dequeue(queue);
        printf("%d ", current->val);

        if (current->left != NULL)
        {
            enqueue(queue, current->left);
        }

        if (current->right != NULL)
        {
            enqueue(queue, current->right);
        }
    }

    free(queue);
}

int cnt;
void cntNode(TreeNode *T)
{
    if (T)
    {
        cnt++;
        cntNode(T->left);
        cntNode(T->right);
    }
}
void doubleOrderTravel(TreeNode *T)
{
    if (T)
    {
        cout << T->val;
        doubleOrderTravel(T->left);
        cout << T->val;
        doubleOrderTravel(T->right);
    }
}
bool judgeBST(TreeNode *T)
{
    if (T)
    {
        bool left, right;
        if (T->left)
        {
            if (T->val > T->left->val)
            {
                left = judgeBST(T->left);
            }
            else
            {
                left = false;
            }
        }
        else
        {
            left = true;
        }
        if (T->right)
        {
            if (T->val < T->right->val)
            {
                right = judgeBST(T->right);
            }
            else
            {
                right = false;
            }
        }
        else
        {
            right = true;
        }
        return left && right;
    }
    return true;
}
int f = 0;
// 非递归交换左右子树
void exchangeLRChild(TreeNode *&T)
{
    TreeNode *r, *p;
    TreeNode *stack[10];
    int top = 0;
    stack[++top] = T;
    while (top > 0)
    {
        /* code */
        p = stack[top--];
        if (p->left || p->right)
        {
            r = p->left;
            p->left = p->right;
            p->right = r;
            stack[++top] = p->left;
            stack[++top] = p->right;
        }
    }
}

int main()
{
    // 创建一个简单的二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 在这里可以进行树的操作，比如遍历、查找等
    exchangeLRChild(root);
    levelOrderTraversal(root);

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
