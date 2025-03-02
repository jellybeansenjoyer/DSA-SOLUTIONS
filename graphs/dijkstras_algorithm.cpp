class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V = adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,
            greater<pair<int,int>>> pq;
        
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto node = pq.top();
            int w = node.first;
            int u = node.second;
            pq.pop();
            for(auto child:adj[u]){
                int v = child.first;
                int wt = child.second;
                int d = w + wt;
                if(d<dist[v]){
                    pq.push({d,v});
                    dist[v] = d;
                }
            }
        }
        return dist;
    }
};