#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
//静态链表实现，基于数组,并没有用到链表
struct Node
{
	char Data;
	int Left, Right;
} T1[99], T2[99];
typedef struct Node Tree;
int check[99];
void settree(Tree T[])
{
	for (int i = 0; i < 99; i++)
	{
		T[i].Left = T[i].Right = -1;
	}
}
void setcheck(int check[])
{
	for (int i = 0; i < 99; i++)
	{
		check[i] = 0;
	}
}
int Read(Tree T[], int n)
{	//将check全部置零
	//check作用用来记录结点的入度。入度为0的结点是根结点
	for (int i = 0; i < n; i++)
	{
		check[i] = 0;
	}
	if (n == 0)
		return -1;
	settree(T);
	char left, right;
	for (int i = 0; i < n; i++)
	{
		cin >> T[i].Data;
		cin.get();

		cin >> left;
		cin.get();
		if (left != '-')
		{
			T[i].Left = left - '0';//将left转为int
			check[T[i].Left] = 1;//将其子树的check值变为1
		}
		else
			T[i].Left = -1;

		cin >> right;
		cin.get();
		if (right != '-')
		{
			T[i].Right = right - '0';
			check[T[i].Right] = 1;
		}
		else
			T[i].Right = -1;
	}
	int i;
	for (i = 0; i < n; i++)//遍历check找到不为0的，返回
		if (!check[i])
			break;
	return i;
}
bool Isomo(int root1, int root2)
{
	if (root1 == -1 && root2 == -1)
		return true; //都是空树
	if ((root1 == -1 && root2 != -1) || (root1 != -1 && root2 == -1))
		return false; //一个空树一个不空
	if (T1[root1].Data != T2[root2].Data)
		return false; //根节点都存在但数值不同
	if (T1[root1].Left != -1 && T2[root2].Left != -1 && T1[T1[root1].Left].Data == T2[T2[root2].Left].Data)
		{printf("data1_1 is%c\n",T1[root1].Data);
		printf("data1_2 is%c\n",T2[root2].Data);
		return Isomo(T1[root1].Right, T2[root2].Right)&&Isomo(T1[root1].Left,T2[root2].Left);} //左子树都存在且值相等，判断右子树
	else{
		printf("data2_1 is%c\n",T1[root1].Data);
		printf("data2_2 is%c\n",T2[root2].Data);												//子树互换比较
		return (Isomo(T1[root1].Right, T2[root2].Left) && Isomo(T1[root1].Left, T2[root2].Right));
	}
	//见ipad
}
int main()
{
	int N1, N2;
	cin >> N1;
	cin.get();
	int root1 = Read(T1, N1);
	cin >> N2;
	cin.get();
	int root2 = Read(T2, N2);
	if (Isomo(root1, root2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cin.get();
	return 0;
}
