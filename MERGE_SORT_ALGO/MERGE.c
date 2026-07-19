#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_sz 100000

void merge(int arr[], int l, int m ,int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[50000],R[50000];

    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j] =arr[m+1+j];

    i = 0,j=0,k+l;
    while(i<n1&&j<n2)
    {
        if(L[i]<R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];;

}

void mergesort(int arr[], int l, int r)
{   if(l<r)
    {
        int m = l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[max_sz];
    int n,i;

    FILE *fp = fopen("Time_complexity_file.csv","w");
    if(fp == NULL)
    {
        printf("ERROR IN OPENING FILE\n");
        return 1;
    }

    fprintf(fp,"n,time(ms)");

    printf("RUNNING MERGESORT FOR DIFFERENT VALUES OF N(n>5000)\n");

    for(n=5000;n<=50000;n+=5000)
    {
        for(i = 0; i < n; i++)
        {
            arr[i] = rand()%100000;
        }

        clock_t start = clock();
        mergesort(arr,0,n-1);
        clock_t end = clock();

        double tt = ((double)(end-start))*1000.0/CLOCKS_PER_SEC;

        printf("n = %d\tTime = %.3f ms\n",n,tt);
        fprintf(fp,"%d,%.3f\n",n,tt);
    }

    fclose(fp);
    printf("Results stored to 'Time_complexity_file.csv'\n");

    return 0;
}
