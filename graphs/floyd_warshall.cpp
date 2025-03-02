  void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int V = mat.size();
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(mat[i][j]==-1){
                    mat[i][j] = 1e9;
                }
            }
        }
        
        for(int k=0; k<V; k++){
            for(int i=0; i<V; i++){
                for(int j=0; j<V; j++){
                    if(mat[i][k]!=1e9&&mat[k][j]!=1e9){
                        mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                    }
                }
            }
        }
        
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(mat[i][j]==1e9){
                    mat[i][j] = -1;
                }
            }
        }
    }