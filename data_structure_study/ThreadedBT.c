//线索二叉树
#include <stdio.h>
#include <stdlib.h>
#define ElemType int;
/*
 * @Author: Windy_Liu
 * @Date: 2022-02-11 00:19:05
 * @Last Modified by:   Windy_Liu
 * @Last Modified time: 2022-02-11 00:19:05
 * 详情见王道https://www.bilibili.com/video/BV1b7411N798?p=47&spm_id_from=pageDriver
 */
//dsa
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *Left, *Right;
    int ltag, rtag;
} ThreadNode, *ThreadTree;
ThreadTree pre = NULL, final;
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T)
    {
        InThread(T); //这个地方换成PreThread就是先序，同理后续也一样
        if (pre->Right == NULL)
        {
            pre->rtag = 1;
        }
    }
}
//中序线索化
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->Left);
        visit(T);
        InThread(T->Right);
    }
}
//后续线索化
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->Left);
        InThread(T->Right);
        visit(T);
    }
}
//先序线索化
void PreThread(ThreadTree T)
{
    if (T)
    {
        visit(T);
        if (T->ltag == 0) //只在tag为1的时候对左儿子进行线索化，避免出现转圈现象
        {
            PreThread(T->Left);
        }
        PreThread(T->Right);
    }
}
void visit(ThreadTree this)
{
    if (this->Left == NULL) //如果左子树为空，建立前驱线索
    {
        this->Left = pre;
        this->ltag = 1;
    }
    if (pre && !pre->Right)
    {
        pre->Right = this; //建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = this;
}