class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int sr,int sc,int dx[],int dy[],int n,int m){
        vis[sr][sc] = 1;
        for(int k=0; k<4; k++){
            int nr = sr + dx[k];
            int nc = sc + dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(grid,vis,nr,nc,dx,dy,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        vector<vector<int>> vis (n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    dfs(grid,vis,i,j,dx,dy,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};