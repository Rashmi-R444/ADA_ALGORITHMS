#include<stdio.h>
#define max 10

void fntopological(int a[max][max], int n)
{
    int in[max] = {0}, out[max], top = -1, stack[max], i,j,k=0;
    for(i = 0; i < n; i ++)
    {
        for(j=0;j<n;j++)
            if(a[j][i]) in[i]++;
    }

    while(1)
    {
        for(int i = 0; i <n; i++)
        {
            if(in[i]==0)
            {
                stack[++top] = i;
                in[i] =-1;
            }
        }

        if(top == -1) break;

        out[k] = stack[top--];
        for( i = 0;i<n;i++ )
            if(a[out[k]][i])in[i]--;
        k++;
    }

    printf("Topological sequence\n");
    for(i =0; i <k;i++) printf("%d", out[i]+1);
    printf("\n");
}

int main()
{
    int a[max][max],n,i,j;
    printf("Enter the noof elemnets:\n");
    scanf("%d", &n);

    printf("Enter adjacency matrix:");
    for(i = 0 ; i < n; i++)
    {
        for(j = 0; j<n;j++)
            scanf("%d", &a[i][j]);
    }
    fntopological(a,n);
    return 0;
}
