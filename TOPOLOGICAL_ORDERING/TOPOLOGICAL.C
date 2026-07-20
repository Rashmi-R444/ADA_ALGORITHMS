#include<stdio.h>
#define max 5

void funct_topological(int a[max][max], int n)
{
    int in[max] = {0}, out[max],top = -1, stack[max],i,j,k=0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            if(a[j][i]) in[i]++;
    }

    while(1)
    {
        for(i = 0; i < n; i++)
        {
            if(in[i] == 0)
            {
                stack[++top] = i;
                in[i] = -1;
            }
        }

        if(top == -1) break;

        out[k] = stack[top--];
        for(i = 0; i < n;i++)
            if(a[out[k]][i]) in[i]--;
        k++;
    }

    if (k != n)
{
    printf("Graph contains a cycle.\n");
    printf("Topological sorting is not possible.\n");
    return;
}

    printf("topological sequence is \n");
    for(i = 0; i < k;i++)
        printf("%d ",out[i]+1);
    printf("\n");
}

int main()
{
    int a[max][max],n,i,j;
    printf("Enter number of vertices\n");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i< n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    funct_topological(a,n);
    return 0;

}
