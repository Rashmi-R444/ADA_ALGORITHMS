#include <stdio.h>
#define V 4
#define INF 99999

void printSol(int dist[V][V])
{
    int i,j;
    for(i = 0; i < V; i++)
    {
        for(j= 0; j < V;j++)
        {
            if(dist[i][j] == INF)
                printf("INF\n");
            else
                printf("%d\t",dist[i][j]);
        }

        printf("\n");
    }
}

void floydwarshall(int graph[V][V])
{
    int dist[V][V];
    int i,j,k;

    for(i = 0; i < V; i++)
    {
        for(j= 0; j < V;j++)
        {
            dist[i][j]  = graph[i][j];
        }
    }

    for(k = 0; k < V;k++)
    {
        for(i = 0; i < V; i++)
        {
            for(j= 0; j < V;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] +  dist[k][j];
            }
        }
    }

    printSol(dist);
}

int main()
{
    int graph[V][V] = {{INF,0,2,INF},
{1, 0, INF,3},
{INF,1, 3, INF},
{INF,3,2, 0}};

    floydwarshall(graph);
    return 0;
}
