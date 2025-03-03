class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            
            int n = grid.size();
            if(grid[0][0]==1||grid[n-1][n-1]==1)    return -1;
            int dx[] = {-1,0,1,0,-1,1,-1,1};
            int dy[] = {0,1,0,-1,-1,1,1,-1};
            queue<pair<int,int>> q;
            q.push({0,0});
            grid[0][0] = 1;
            int ans = INT_MAX;
            while(!q.empty())
            {
                auto node = q.front();
                q.pop();
                int sx = node.first;
                int sy = node.second;
                if(sx==n-1&&sy==n-1){
                    ans = min(ans,grid[sx][sy]);
                }
                for(int i=0;i<8;i++){
                    int nx = sx + dx[i];
                    int ny = sy + dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny]=grid[sx][sy]+1;   
                    }
                }
            }
            if(ans==INT_MAX)    return -1;
            return ans;
        }
    };