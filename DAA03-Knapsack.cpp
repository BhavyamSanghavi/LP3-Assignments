#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int W, int wt[],int val[], int n, int i,vector<vector<int>>&dp)
    {
        if(i>=n || W<=0) return 0;
        if(dp[i][W]!=-1) return dp[i][W];
        int pick=0;
        if(W-wt[i]>=0)
        pick+=val[i]+solve(W-wt[i],wt,val,n,i+1,dp);
        int nopick=solve(W,wt,val,n,i+1,dp);
        
        return dp[i][W]=max(pick,nopick);
    }
    
    int solveTab(int W,int wt[],int val[], int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int w=0;w<=W;w++)
            {
                int pick=0;
                if(w-wt[i]>=0)
                pick=val[i]+dp[i+1][w-wt[i]];
                int nopick=dp[i+1][w];
                dp[i][w]=max(pick,nopick);
            }
        }
        return dp[0][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        //   return solve(W,wt,val,n,0,dp);
        return solveTab(W,wt,val,n);
    }

int main() {
    int W = 269; // Capacity
    vector<int> wt = {95, 4, 60, 32, 23, 72, 80, 62, 65, 46};
    vector<int> val = {55, 10, 47, 5, 4, 50, 8, 61, 85, 87};

    cout << "Maximum value: " << knapsack(W, wt, val) << endl;
    return 0;
}
