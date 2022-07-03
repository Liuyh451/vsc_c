/*二叉排序树  左子树<根节点<右子树
 * @Author: Windy_Liu
 * @Date: 2022-03-12 17:04:22
 * @Last Modified by: Windy_Liu
 * @Last Modified time: 2022-03-12 17:13:56
 */
#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
typedef struct BSTNode
{
    int key; // value type is changeable
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
BSTree InitTree(BSTree T)
{
    T = (BSTree)malloc(sizeof(struct BSTNode));
    T->lchild = T->rchild = NULL;
    return T;
}
BSTree TSearch(BSTree T, int key)
{
    if (T)
    {
        if (T->key == key)
        {
            return T; //查找成功
        }
        else if (T->key < key)
        {
            return TSearch(T->rchild, key); //如果结点的值小于待找值就去左子树中找
        }
        else
        {
            return TSearch(T->lchild, key); //这个地方需要return 因为函数要求有返回值
        }
    }
}
/* 非递归查找
BSTree TSearch(BSTree T, int key)
{
    while (T && key != T->key)
    {
        if (key < T->key)
        {
            T = T->lchild;
        }
        else
        {
            T = T->rchild;
        }
    }
    return T;
}
*/
void Insert(BSTree T, int X)
{
    if (T == NULL)
    {   //到最后插入时，结点肯定为空，所以要新建结点
        T=(BSTree)malloc(sizeof(BSTNode));
        T->lchild=T->rchild=NULL;
        T->key = X;
        printf("insert success!\n");
    }
    else if (X < T->key)
    {
        Insert(T->lchild, X);//如果待插入值小于结点值，就去左子树
    }
    else if (X == T->key)
    {
        printf("existed value\n");//相等，已经存在值，插入失败
    }
    else
    {
        Insert(T->rchild, X);//如果待插入值大于结点值，就去右子树
    }
}
