#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto node = q.front();
                int nr,nc;
                int r = node.first;
                int c = node.second; 
                q.pop();

            for(int k=0; k<4; k++){
                nr = r+dx[k];
                nc = c+dy[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=2;
                }
            }
        }
        if(!q.empty())
        ans++;  
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)   return -1;
            } 
        }
        return ans;
    }
};

// Time Complexity : O(M∗N)
// Space Complexity: O(M∗N)



