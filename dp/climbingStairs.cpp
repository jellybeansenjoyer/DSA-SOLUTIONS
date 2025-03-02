#include<bits/stdc++.h>
using namespace std;
int topBottom(int n,int dp[]){
    if(n<=2)    return n;
    if(dp[n]!=-1)   return dp[n];
    return dp[n] = topBottom(n-1,dp) + topBottom(n-2,dp);
}
int bottomUp(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-2]+dp[i-1];
    }
    return dp[n];
}
int climbStairs(int n) {
    if(n<=1)    return n;
    int cur;
    int prev2 = 1;
    int prev = 1;
    for(int i=2;i<=n;i++){
        cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return cur;
    }
int main(){
    cout<<"Enter the size"<<endl;
    int n;
    cin>>n;
    // int dp[n+1];
    // memset(dp,-1,sizeof dp);
    // cout<<topBottom(n,dp)<<endl;
    cout<<bottomUp(n)<<endl;

}