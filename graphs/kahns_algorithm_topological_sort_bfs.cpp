class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int node,vector<int>& vis,stack<int>& st,vector<vector<int>> &adj){
        vis[node] = 1;
        for(auto child: adj[node]){
            if(!vis[child]){
                dfs(child,vis,st,adj);
            }
        }
        st.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        stack<int> st;
        int n = adj.size();
        vector<int> vis(n,0);
        
        for(int i=0; i<n; i++){
                if(!vis[i]){
                 dfs(i,vis,st,adj);   
                }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};