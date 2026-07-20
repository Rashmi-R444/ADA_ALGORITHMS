#include<stdio.h>
#define V 4

void printmat(int reach[V][V])
{
    int i,j;
    printf("Transitive closure of a matrix\n");
    for(i = 0; i < V;i++)
    {
        for(j = 0; j < V;j++)
        {
            printf("%d ",reach[i][j]);
        }
        printf("\n");
    }
}

void warshall(int graph[V][V])
{
    int i,j,k;
    int reach[V][V];
    for(i = 0;i <V;i++)
    {
        for(j=0;j<V;j++)
        {
            reach[i][j] = (graph[i][j]!=0)?1:0;
        }
    }

    for(k = 0; k < V;k++)
    {
        for(i = 0; i <V;i++)
        {
            for(j = 0; j< V;j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k]&&reach[k][j]);
            }
        }
    }
    printmat(reach);
}

int main()
{
            int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {0,0,0,0}};

    warshall(graph);
    return 0;
}
