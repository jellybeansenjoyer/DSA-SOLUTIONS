class Solution {
public:
    void dfs(vector<vector<char>>& board,int sr,int sc,int dx[],int dy[],int n,int m,vector<pair<int,int>>& vec,bool& isEdged)   {
        board[sr][sc]='-';
        vec.push_back({sr,sc});
        if(sr==0||sc==0||sr==n-1||sc==m-1)  isEdged = true;
        for(int k=0; k<4; k++){
            int nr = sr + dx[k];
            int nc = sc + dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O'){
                dfs(board,nr,nc,dx,dy,n,m,vec,isEdged);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        bool isEdged = false;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    vec.clear();
                    isEdged = false;
                    dfs(board,i,j,dx,dy,n,m,vec,isEdged);
                    if(isEdged){
                        for(auto ele:vec){
                            board[ele.first][ele.second] = '-';
                        }
                    }else{
                        for(auto ele:vec){
                            board[ele.first][ele.second] = 'X';
                        }
                    }
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='-'){
                    board[i][j]='O';
                }
            }
        }

    }
};