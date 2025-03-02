#include<bits/stdc++.h>
using namespace std;
int topDown(int n,int dp[]){
    if(n<=1)    return n;
    if(dp[n]!=-1)   return dp[n];
    return dp[n] = topDown(n-1,dp) + topDown(n-2,dp);
}
void bottomUp(int n){
    // int dp[n+1];
    // dp[0] = 0;
    // dp[1] = 1;
    // for(int i=2; i<=n; i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // for(int i=0; i<=n; i++){
    //     cout<<dp[i]<<",";
    // }

    
    int prev = 1;
    int cur;
    int prev2 = 0;
    vector<int> ans;
    ans.push_back(prev2);
    ans.push_back(prev);
    for(int i=2; i<=n; i++){
        cur = prev +prev2;
        ans.push_back(cur);
        prev2 = prev;
        prev = cur;
    }
    for(int i=0; i<=n; i++){
        cout<<ans[i]<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter the nth element"<<endl;
    cin>>n;
    // int dp[n+1];
    // memset(dp,-1,sizeof dp);
    // for(int i=0; i<=n;i++){

    //     int ans = topDown(i,dp);
    //     cout<<"The "<<i<<"th Element is "<<ans;
    //     cout<<endl;
    // }
    bottomUp(n);
}