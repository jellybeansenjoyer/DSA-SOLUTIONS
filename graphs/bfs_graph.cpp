class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void solve(vector<vector<int>> &adj,vector<int> &ans,vector<int>& vis,
                        int node){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        ans.push_back(node);
        
        while(!q.empty()){
            int elem = q.front();
            q.pop();
            for(auto child:adj[elem]){
                if(!vis[child]){
                    q.push(child);
                    vis[child] =1;
                    ans.push_back(child);
                }
            }
        }
        
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        vector<int> vis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                solve(adj,ans,vis,i);
            }
        }
        return ans;
    }
};