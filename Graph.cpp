#include <iostream>
using namespace std;
typedef struct Arcnode
{
    int adjvex;
    struct Arcnode *next;
} Arcnode;
typedef struct
{
    int data;
    Arcnode *firstarc;
} VNode;
typedef struct
{
    VNode adjlist[10];
    int n, e;
} AGraph;

void addEdge(AGraph *&graph, int start, int end)
{
    // Add an edge from start to end
    Arcnode *newNode = (Arcnode *)malloc(sizeof(Arcnode));
    newNode->adjvex = end;
    newNode->next = graph->adjlist[start].firstarc;
    graph->adjlist[start].firstarc = newNode;
}
// 如果图是无向图，入等于出度，直接求出度简单
int getDegreeInUndir(AGraph *G, int v)
{
    int degree = 0;
    Arcnode *p = G->adjlist[v].firstarc;
    while (p)
    {
        degree++;
        p = p->next;
    }
    return degree;
}
//
int getDegreeIDir(AGraph *G, int v)
{
    int degree = 0;
    for (int i = 0; i < G->n; i++)
    {
        Arcnode *p = G->adjlist[i].firstarc;
        if (i == v)
        {
            while (p)
            {
                degree++;
                p = p->next;
            }
        }
        else
        {
            while (p)
            {
                if (p->adjvex == v)
                {
                    degree++;
                }
                p = p->next;
            }
        }
    }
    return degree;
}
int getInDegree(AGraph *G, int v)
{
    int cnt = 0;
    for (int i = 0; i < G->n; i++)
    {
        Arcnode *p = G->adjlist[i].firstarc;
        while (p)
        {
            if (p->adjvex == v)
            {
                cnt++;
            }
            p = p->next;
        }
    }
    return cnt;
}
int degree[10] = {0};
void getAllDegree(AGraph *G, int degree[])
{
    // 如果是无向图，要对完成后的数组除以2，有向图无需
    for (int i = 0; i < G->n; i++)
    {
        Arcnode *p = G->adjlist[i].firstarc;
        while (p)
        {
            degree[p->adjvex]++;
            degree[i]++;
            p = p->next;
        }
    }
}

int topSort(AGraph *G)
{   //实际上这里用队列比较好，懒得改了
    int S[10];
    int top = -1;
    getAllDegree(G, degree);
    for (int i = 0; i < G->n; i++)
    {
        if (degree[i] == 0)
        {
            S[++top] = i;
        }
    }
    int cnt=0;
    while (top != -1)
    {
        cout << S[top] << endl;
        Arcnode *p = G->adjlist[S[top--]].firstarc;
        cnt++;
        while (p)
        {
            degree[p->adjvex]--;
            if (degree[p->adjvex] == 0)
            {
                S[++top] = p->adjvex;
            }
        }

    }
    return cnt==G->n?1:0;
}

int visited[10] = {0};
void DFS(AGraph *G, int v)
{
    Arcnode *p = G->adjlist[v].firstarc;
    visited[v] = 1;
    cout << G->adjlist[v].data << endl;
    while (p)
    {
        /* code */
        if (visited[p->adjvex] == 0)
        {
            DFS(G, p->adjvex);
        }
        p = p->next;
    }
}
void BFS(AGraph *G, int v)
{
    int Q[10];
    int front = 0, rear = 0;
    Q[rear] = v;
    rear = (rear + 1) % 10;
    visited[v] = 1;
    while (front != rear)
    {
        int i = Q[front];
        front = (front + 1) % 10;
        Arcnode *p = G->adjlist[i].firstarc;

        while (p)
        {
            /* code */
            if (visited[p->adjvex] == 0)
            {
                visited[i] = 1;
                cout << G->adjlist[i].data << endl;
                Q[rear] = p->adjvex;
                rear = (rear + 1) % 10;
            }
            p = p->next;
        }
    }
}
int main()
{
    AGraph *graph;
    graph->n = 6; // 6 vertices
    graph->e = 0; // 0 edges initially

    addEdge(graph, 1, 2);
    cout << graph->adjlist[1].firstarc->adjvex;
    return 0;
}