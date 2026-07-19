  #include<stdio.h>
  #include<limits.h>

  #define V 5

  int minKey(int key[],int mstSet[])
  {
      int min = INT_MAX, min_index = -1;
      for(int v = 0; v<V;v++)
        if(!mstSet[v]&&key[v]<min) min = key[v], min_index = v;
      return min_index;
  }

  void primMST(int graph[V][V])
  {
    int parent[V],key[V],mstSet[V]={0},cost =0;
    for(int i = 0;i<V;i++)key[i]=INT_MAX;
    key[0]=0;
    parent[0]=-1;

    for(int count = 0; count < V-1;count++)
    {
        int u = minKey(key,mstSet);
        mstSet[u]=1;
        for(int v =0 ; v< V;v++)
            if(graph[u][v]&&!mstSet[v]&&graph[u][v]<key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edges\tWeight\t\n");
    for(int i = 1;i <V;i++){
        printf("%d--%d==%d\n",parent[i],i,graph[i][parent[i]]);
        cost += graph[i][parent[i]];
    }
    printf("Minimum cost = %d",cost);

  }

  int main()
  {
      int graph[V][V]={{0, 2, 6, 0,3},
{2, 0, 8, 9,7},
{6, 8, 0, 4,2},
{0, 9,4,0,3},
{3,7,2,3,0}};
    primMST(graph);
      return 0;
  }
