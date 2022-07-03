//双亲表示法
// https://blog.csdn.net/lady_killer9/article/details/87925430
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Maxsize 100
typedef int ElemType;

typedef struct
{
    ElemType data;
    int parent; //记录双亲的数组下标
} PTNode;
typedef struct
{
    PTNode nodes[Maxsize];
    int n; //节点数量
} PTree;
//******************基本操作函数********************
//初始化树 参数：树T，作用：规定树的数据，以及树的双亲，没有则为-1
void InitTree(PTree T)
{
    for (int i = 0; i < Maxsize; i++)
    {
        T.nodes[i].data = '#';
        T.nodes[i].parent = -1;
    }
    T.n = 0;
}
//插入树结点 参数：树T；结点数据data；父亲结点par

bool InsertNode(PTree T, ElemType node)
{
	
	if (node != '#')
	{
		T.nodes[T.n++].data = node;//插入到双亲数组中
		return true;
	}
	return false;
}
/*void InsertTree(PTree T, int data, int par)
{
    T.nodes[T.n++].data = data; //结点自加一
    T.nodes[T.n++].parent = par;
    printf("插入成功");
}*/
//插入双亲数组的双亲域 参数：树T ，结点node1,结点node2
//作用：使双亲数组,node2对应的双亲域为node1的标
bool InsertParent(PTree T, int node1, int node2)
{
    int place1, place2;
    place1 = place2 = -1;
    for (int i = 0; i < T.n; i++)
    {
        if (node1 == T.nodes[i].data)
            place1 = i; //查找值为
        if (node2 == T.nodes[i].data)
            place1 = i; //如果结点的值等于树中原有的数据，则记录
    }
    if (place1 != -1 && place2 != -1)
    {
        T.nodes[place2].parent = place1;
        return true;
    }
}
//得到某结点入�? 参数：树T，结点node 结点不存在返�?-1
int GetIndegree(PTree T, int node)
{
    int flag = -1, cnt = 0;
    for (int i = 0; i < T.n; i++)
    {
        if (T.nodes[i].data == node)
        {
            flag = i;
        }
    }
    if (flag != -1)
    {
        if (T.nodes[flag].parent != -1)
            return 1; //双亲只有一个，入度表示双亲
        return 1;
    }
    else
    {
        return -1;
    }
}
//得到某结点出�? 参数：树T，结点node 结点不存在返�?-1
int GetOutdegree(PTree T, ElemType node)
{
    int flag = -1, cnt = 0;
    for (int i = 0; i < T.n; i++)
    {
        if (T.nodes[i].data == node)
        {
            flag = i;
        }
    }
    if (flag != -1)
    {
        for (int i = 0; i < T.n; i++)
        {
            if (T.nodes[i].parent == flag)
            {
                cnt++;
            }
        }
        return cnt;
    }
    else
    {
        return -1;
    }
}
//先序遍历 参数：树T,根节点下�?
void PreOrder(PTree T, int i)
{
    if (T.n != 0)
    {
        printf("%d", T.nodes[i].data);
        for (int j = 0; j < T.n; j++)
        {
            if (T.nodes[j].parent == i)
                PreOrder(T, j);
        }
    }
}
//后序遍历 参数：树T,根节点下�?
void PostOrder(PTree T, int i)
{
    if (T.n != 0)
    {
        for (int j = 0; j < T.n; j++)
        {
            if (T.nodes[j].parent == i)
                PreOrder(T, j);
        }
        printf("%d", T.nodes[i].data);
    }
}

//层序遍历 参数：树T
void LevelOrder(PTree T, int i)
{   int cnt=0;
    printf("%d", T.nodes[i].data);
    for(int j=0;j<T.n;j++){
        if(T.nodes[j].parent==i){
            printf("%d", T.nodes[i].data);
            cnt++;
        }
    }
    i=i+cnt+1;
    LevelOrder(T,i);
}
//**********************************功能实现函数*****************************//
//创建树，调用InsertNode,InsertParent

void CreateTree(PTree T)
{
	int nodenum = 0;
	int parent;
	ElemType node,node1,node2;
	printf("请输入树的结点个�?:");
    scanf("%d",&nodenum);
	parent = nodenum - 1;
	printf("请输入树的结点名称（空格隔开�?:");
	while (nodenum--)
	{   scanf("%d",&node);
		InsertNode(T,node);
	}
	printf("请输入树的结点间的双亲关系（一对为一双亲关系，A B表示A为B的双亲）:\n");
	while (parent--)
	{   scanf("%d%d",&node1,&node2);
		InsertParent(T,node1,node2);
	}
	printf("\n");
}
//入度
void Indegree(PTree T)
{
	ElemType node;
	int indegree;
	printf("请输入结点名�?:\n");
    scanf("%d",&node);
	indegree = GetIndegree(T, node);
	if (-1 != indegree)
		printf("%d",indegree);
	else
		printf("不存�?");
}
//出度
void Outdegree(PTree T)
{
	ElemType node;
	int outdegree;
	printf("请输入结点名�?:\n");
    scanf("%d",&node);
	outdegree = GetOutdegree(T, node);
	if (-1 != outdegree)
		printf("%d",outdegree);
	else
		printf("结点不存在�?");
}
//遍历功能函数 调用PreOrder InOrder PostOrder LevelOrder
void Traverse(PTree T)
{
	int choice;
	while (1)
	{
		printf("********1.先序遍历    2.后序遍历*********\n");
		printf("********3.层次遍历    4.返回上一单元*********\n");
		printf("请输入菜单序号：\n");
		scanf("%d", &choice);
		if (4 == choice) break;
		switch (choice)
		{
		case 1: {printf("树先序遍历序�?:");PreOrder(T,0);printf("\n");}break;
		case 2: {printf("树后序遍历序�?:");PostOrder(T,0);printf("\n");}break;
		case 3: {printf("树层序遍历序�?:");LevelOrder(T,0);printf("\n");}break;
		default:printf("输入错误！！！\n");break;
		}
	}
}
//菜单
void menu()
{
	printf("********1.创建     2.某点入度*********\n");
	printf("********3.某点出度 4.遍历*************\n");
	printf("********5.退出\n");
}
//主函数
int main()
{
	PTree T;
	int choice = 0;
	InitTree(T);
	while (1)
	{
		menu();
		printf("请输入菜单序号：\n");
 
		scanf("%d", &choice);
		if (5 == choice) break;
		switch (choice)
		{
		case 1:CreateTree(T);break;
		case 2:Indegree(T);break;
		case 3:Outdegree(T);break;
		case 4:Traverse(T);break;
		default:printf("输入错误！！！\n");break;
		}
	}
	return 0;
}