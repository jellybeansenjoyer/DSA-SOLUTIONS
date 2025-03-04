#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
int maximumPoints(int n, vector<vector<int>> &points, int c,vector<vector<int>> &dp){
    if(n==0){
        return points[n][c];
    }    
    if(dp[n][c]!=-1)    return dp[n][c];
    int maxm = -1e8;
    for(int i=0;i<3;i++){
        if(i!=c){
            maxm = max(maxm,points[n][c]+maximumPoints(n-1,points,i,dp));
        }
    }
    return dp[n][c] = maxm;
}
int topDown(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int maxm = -1e8;
    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    for(int i=0;i<3;i++){
        maxm = max(maxm,maximumPoints(n-1,points,i,dp));
    }
    return maxm;
}