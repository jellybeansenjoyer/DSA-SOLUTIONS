#include <bits/stdc++.h>
int solve(int i,int j,vector<vector<int>>&dp,int dx[],int dy[]){
	if(i==0 &&j==0)	return 1;
	if(dp[i][j]!=-1)	return dp[i][j];
	int sum = 0;
	for(int k=0;k<2;k++){
		int ni = i+dx[k];
		int nj = j+dy[k];
		if(ni>=0 && nj>=0){
			sum+=solve(ni,nj,dp,dx,dy);
		}
	}
	return dp[i][j] = sum;
} 
int uniquePaths(int m, int n) {
	// Write your code here.
	int dx[] = {-1,0};
	int dy[] = {0,-1};
	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	return solve(m-1,n-1,dp,dx,dy); 
}
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	int dp[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0] = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i-1>=0){
				dp[i][j]+=dp[i-1][j];
			}
			if(j-1>=0){
				dp[i][j]+=dp[i][j-1];
			}
		}
	}
	return dp[m-1][n-1];
}