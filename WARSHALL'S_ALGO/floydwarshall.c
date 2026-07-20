#include<stdio.h>
#define V 4
# define INF 99999

void printsolu(int dist[V][V])
{
    int i,j;
    for(i = 0 ; i < V; i++)
    {
        for(j = 0; j < V;j++)
        {
            if(dist[i][j] == INF)
                printf("INF\n");
            else
                printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}

void floydwarshall(int graph[V][V])
{
    int i,j,k;
    int dist[V][V];

    for(i = 0; i < V; i++)
    {
        for(j = 0 ; j <V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }


    for(k = 0 ; k < V; k++)
    {
        for(i = 0; i < V; i++)
        {
            for(j = 0 ; j < V; j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

    printsolu(dist);
}

int main()
{
     int graph[V][V] = {{2,3,8,INF},
                        {1,3,INF,8},
                        {4,INF,6,8},
                        {6,2,INF,5}};
            floydwarshall(graph);
            return 0;
}
