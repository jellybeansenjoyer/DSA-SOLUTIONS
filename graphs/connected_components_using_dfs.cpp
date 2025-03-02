
class Solution {
  public:
    void dfs(vector<int>& vis, vector<vector<int>>& adj, int node, vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto child: adj[node]){
            if(!vis[child]){
                dfs(vis,adj,child,ans);
            }
        }
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(v);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> final_ans;
        vector<int> ans;
        vector<int> vis(v,0);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                ans.clear();
                dfs(vis,adj,i,ans);
                sort(ans.begin(),ans.end());
                final_ans.push_back(ans);
            }
        }
        return final_ans;
    }
};