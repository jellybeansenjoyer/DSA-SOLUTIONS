class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr, int sc, int n,int m,int color,int ogColor,int dx[],int dy[]){
        image[sr][sc] = color;
        for(int k=0; k<4; k++){
            int nr = sr + dx[k];
            int nc = sc + dy[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==ogColor){
                dfs(image,nr,nc,n,m,color,ogColor,dx,dy);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc]==color)    return image;
        dfs(image,sr,sc,n,m,color,image[sr][sc],dx,dy);
        return image;
    }
};