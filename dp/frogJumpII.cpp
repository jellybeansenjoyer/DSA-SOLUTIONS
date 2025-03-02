#include<bits/stdc++.h>
using namespace std;

int topDown(int n,vector<int> &height,int dp[],int k){
    if(n==1)    return 0;
    if(dp[n]!=-1)   return dp[n];
    int minm = INT_MAX;
    for(int i=0;i<k;i++){
        if((k-i)<=(n-1))
        minm = min(minm,abs(height[n-1-(k-i)]-height[n-1])+topDown(n-(k-i),height,dp,k));
    }
    // return dp[n] = min(abs(height[n-1]-height[n-2])+topDown(n-1,height,dp),abs(height[n-1]-height[n-3])+topDown(n-2,height,dp));
    return dp[n] = minm;
}
int topDown2(int n,vector<int> &height,int dp[],int k){
    
    if(n==0)    return 0;
    if(dp[n]!=-1)   return dp[n];
    int minm = INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0)
        minm = min(minm,abs(height[n]-height[n-i])+topDown(n-i,height,dp,k));
    }
    return dp[n] = minm;
}

int bottomUp(int n, int k, vector<int> &height){
    int dp[n+1];
    memset(dp,-1,sizeof dp);
    if(n==1)    return 0;
    dp[0]= 0;

    for(int i=1; i<n;i++){
        int minm = INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0)
            minm = min(minm,abs(height[i]-height[i-j])+dp[i-j]);
        }
        dp[i] = minm;
    }
    return dp[n-1];

}

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    int dp[n+1];
    memset(dp,-1,sizeof dp);
    return topDown(n,height,dp,k);
}
int main(){

}