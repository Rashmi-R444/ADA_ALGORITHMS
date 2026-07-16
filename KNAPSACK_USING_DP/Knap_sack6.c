 #include<stdio.h>
 #include<string.h>

 #define max_item 100
 #define max_weight 1000

 int dp[max_item][max_weight+1];

 int max(int a, int b)
 {
     return(a>b)?a:b;
 }

 int knapsack(int wt[],int val[], int n, int W)
 {
     if(n==0||W==0)
        return 0;

     if(dp[n][W] != -1)
        return dp[n][W];

     if(wt[n-1]>W)
        dp[n][W] = knapsack(wt,val,n-1,W);

     else
        dp[n][W] = max(val[n-1] + knapsack(wt,val,n-1,W-wt[n-1]),knapsack(wt,val,n-1,W));

    return dp[n][W];
 }

 int main()
 {
     int val[] = {200,300,459};
     int wt[] = {11,22,33};
     int W = 50;
     int n = sizeof(val)/sizeof(val[0]);

     memset(dp,-1,sizeof(dp));

     int maxprofit = knapsack(wt,val,n,W);
     printf("Maximum profit = %d\n",maxprofit);

     return 0;

 }
