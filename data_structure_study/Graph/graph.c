#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct GNode *PtrToGNode;
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;
struct GNode
{
    int Nv; //顶点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;
MGraph CreateGraph(int VertexNum)
{
    Vertex V, W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++)
    {
        for (W = 0; W < Graph->Nv; W++)
        {
            Graph->G[V][W] = INFINITY;
        }
    }
    return Graph;
}
void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    //Graph->G[E->V2][E->V1]=E->Weight;//如果是无向图需要加入这句话
}
MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            scanf("%d%d%d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }
    for (int V = 0; V < Graph->Nv; V++)
    {
        scanf(" %c", &(Graph->Data[V]));
    }
    return Graph;
}
bool Visited[] = {0};
void DFS(MGraph G, Vertex V)
{
    printf("Visiting----->%d", V);
    printf("    Data----->%c\n", G->Data[V]);
    Visited[V] = true;
    for (int W = 0; W < G->Nv; W++)
    {
        if (G->G[V][W] == 1)
        {
            if (!Visited[W])
            {

                DFS(G, W);
            }
        }
    }
}
bool IsEdge(MGraph G, Vertex V, Vertex W)
{
    return G->G[V][W] < INFINITY ? true : false;
}
void BFS(MGraph G, Vertex S)
{
    int Q[100];
    int font = 0, rear = 0;
    bool Visited[] = {0};
    Vertex V, W;
    printf("Visiting1----->%d", S);
    printf("    Data----->%c\n", G->Data[S]);
    Visited[S] = true;
    Q[rear++] = S;
    while (rear != font)
    {
        V = Q[font++];
        for (W = 0; W < G->Nv; W++)
        {
            if (!Visited[W] && IsEdge(G, V, W))
            {
                printf("Visiting2----->%d", W);
                printf("    Data----->%c\n", G->Data[W]);
                Visited[W] = true;
                Q[rear++] = W;
            }
        }
    }
}

int main()
{
    MGraph Gp = BuildGraph();
    //DFS(Gp,0);
    BFS(Gp, 0);
    return 0;
}