#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_size 100000

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 =r-m;

    int L[50000],R[50000];
    for(int i = 0;i<n1;i++)
    {
        L[i] = arr[l+i];
    }
    for(j = 0; j<n2;j++)
        R[j] = arr[m+1+j];

    i=0;j=0;k=1;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergesort(int arr[], int l, int r)
{
    if(l<r)
    {
                int m = l+ (r-l)/2;

                mergesort(arr,l,m);
                mergesort(arr,m+1,r);

                merge(arr,l,m,r);

    }

}

int main()
{
    int arr[max_size];
    int n;

    FILE *fp = fopen("Time_complexity_data.csv", "w");
    if(fp == NULL)
    {
        printf("error opening the file\n");
        return 0;
    }

    fprintf(fp,"n,time(ms)\n");

    printf("Running merge sort for differnt values from n> 5000");
    for(n = 5000; n <= 50000; n+= 5000)
    {
        for(int i = 0; i < n ;i++)
        {
            arr[i] = rand()%100000;
        }

        clock_t start = clock();
        mergesort(arr,0,n-1);
        clock_t end = clock();

        double timetaken = ((double)(end - start))*1000.0/CLOCKS_PER_SEC;

        printf("n = %d\ttime taken = %3.f ms\n", n, timetaken);
        fprintf(fp,"%d,%3.f\n",n,timetaken);
    }

    fclose(fp);

    printf("Results saved to 'time_complexity_data.csv'\n");
    return 0;
}
