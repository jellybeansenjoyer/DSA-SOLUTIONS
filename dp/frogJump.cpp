#include<bits/stdc++.h>
using namespace std;
int topDown(int n,vector<int> &height,int dp[]){
    if(n==1)    return 0;
    if(n==2)    return abs(height[n-1]-height[n-2]);
    if(dp[n]!=-1)   return dp[n];
    return dp[n] = min(abs(height[n-1]-height[n-2])+topDown(n-1,height,dp),abs(height[n-1]-height[n-3])+topDown(n-2,height,dp));
}
int minCost(vector<int>& height) {
    // Code here
int n = height.size();
if(n==1)    return 0;
if(n==2)    return abs(height[1]-height[0]);
int prev2 = 0;
int cur;
int prev = abs(height[1]-height[0]);
for(int i=3;i<=n;i++){
    cur = min(abs(height[i-1]-height[i-2])+prev,abs(height[i-1]-height[i-3])+prev2);
    prev2 = prev;
    prev = cur;
 }
 return cur;
}
int bottomUp( vector<int>& height)
{
    int n = height.size();
    int dp[n+1];
    memset(dp,-1,sizeof dp);
    dp[1] = 0;
    dp[2] = abs(height[1]-height[0]);
    for(int i=3;i<=n;i++){
        dp[i] = min(abs(height[i-1]-height[i-2])+dp[i-1],abs(height[i-1]-height[i-3])+dp[i-2]);
     }
     return dp[n];
}
int main() {
    // Code here
    int n;
    cin>>n;
    vector<int>& height;
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    int dp[n+1];
    memset(dp,-1,sizeof dp);
    return topDown(n,height,dp);
}