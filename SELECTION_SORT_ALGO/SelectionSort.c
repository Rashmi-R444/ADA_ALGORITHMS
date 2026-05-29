#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_size 100000

void selectionSort(int arr[], int n)
{
    int i, j, minId, temp;

    for( i = 0; i < n-1 ; i++)
    {
        minId = i;
        for(j=i+1; j < n; j++)
        {
            if(arr[j]<arr[minId])
                minId = j;
        }
        temp = arr[minId];
        arr[minId] = arr[i];
        arr[i] = temp;
    }
}

void main()
{
    int arr[max_size];
    int n;

    FILE *fp = fopen("time_complexity_data.csv", "w");
    if(fp == NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    fprintf(fp, "n,time(ms)\n");

    printf("Running Selection Sort for the values n>5000....\t");
    for(n = 5000; n<=50000; n+= 5000)
    {
        for(int i = 0; i<n; i++ )
        {
            arr[i] = rand() % 100000;
        }

        clock_t start = clock();
        selectionSort(arr,n);
        clock_t end = clock();

        double time_taken = ((double)(end-start))*1000.0/CLOCKS_PER_SEC;

        printf("n = %d\t Time = %.3f\n", n, time_taken);
        fprintf(fp, "%d,%.3f\n", n, time_taken);

    }

    fclose(fp);
    printf("\nTime results saved to 'time_complexity_data.csv'.\n");
    return 0;
}
