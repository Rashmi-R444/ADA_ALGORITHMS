#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return ((int(*)[3])a)[0][2] - ((int(*)[3])b)[0][2];
}

int find(int parent[], int i)
{
    if(parent[i]!=i)
        parent[i] = find(parent,parent[i]);
    return parent[i];
}

void unite(int u,int v, int parent[], int rank[])
{
    u = find(parent,u), v = find(parent,v);
    if(rank[u]<rank[v]) parent[u]=v;
    else if(rank[u]>rank[v]) parent[v]=u;
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}

void krushkal(int n, int edges[][3], int e)
{
    qsort(edges,e,sizeof(edges[0]),cmp);
    int rank[n],parent[n],cost = 0;

    for(int i = 0; i < n;i++)parent[i]=i,rank[i]=0;
    printf("edges in mst\n");
    for(int i = 0; i <e;i++)
    {
        int u = find(parent,edges[i][0]),v=find(parent,edges[i][1]);
        if(u!=v)
        {
            unite(u,v,parent,rank);
            cost += edges[i][2];
            printf("%d--%d==%d\n",edges[i][0],edges[i][1],edges[i][2]);
        }
    }

    printf("mst = %d",cost);
}

int main()
{
     int edges[5][3] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
     krushkal(5,edges,5);
     return 0;
}
