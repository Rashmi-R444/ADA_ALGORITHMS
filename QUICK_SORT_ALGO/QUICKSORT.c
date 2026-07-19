 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>

 #define max_sz 100000

 void swap(int *a,int *b)
 {
     int temp = *a;
     *a = *b;
     *b = temp;
 }

 int partition(int arr[], int low, int high)
 {
     int pivot = arr[high];
     int i = (low-1);

     for(int j = low; j<=high -1;j++)
     {
         if(arr[j]<=pivot)
         {
             i++;
             swap(&arr[i],&arr[j]);
         }
     }
     swap(&arr[i+1],&arr[high]);
     return (i+1);
 }

 void quicksort(int arr[], int low, int high)
 {
     if(low<high)
     {
         int pi = partition(arr,low,high);
         quicksort(arr,low,pi-1);
         quicksort(arr,pi+1,high);
     }
 }

 int main()
 {
     int arr[max_sz];
     int n;

    FILE *fp = fopen("time_complexity_file.csv","w");
    if(fp==NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    fprintf(fp,"n,time(ms)\n");

    printf("RUNNING QUICK SORT FOR THE VALUES n (N > 5000)....\n");
    for( n = 5000; n<=50000;n+=5000)
    {
        for(int i = 0; i <n ;i++)
        {
            arr[i]= rand()%100000;
        }

        clock_t start = clock();
        quicksort(arr,0,n-1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) * 1000.0/CLOCKS_PER_SEC;

        printf("n = %d\tTime = %.3f ms\n",n,time_taken);
        fprintf(fp,"%d,%.3f\n",n,time_taken);
    }

    fclose(fp);
    printf("\nResult stored in 'time_complexity_file.csv'\n");
    return 0;
 }

