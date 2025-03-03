#include<bits/stdc++.h>
using namespace std;
int topDown(vector<int> &nums, int n, int dp[]){
        if(n==0)    return nums[n];
        if(n<0)     return 0;
        if(dp[n]!=-1)   return dp[n];
    
        int pick = nums[n] + solve(nums,n-2,dp);
        int not_pick = solve(nums,n-1,dp);
        int maxm = max(pick,not_pick);
        
        return dp[n] = maxm;
    }
int maximumNonAdjacentSum(vector<int> &nums){
        // Write your code here.
        int n = nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        return solve(nums,n-1,dp);
    
}
}
int main(){
    int n;
    cin >> n;
    int dp[n+1];

}