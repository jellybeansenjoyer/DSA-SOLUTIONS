
class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    vector<int> getParents(){
        vector<int> ans;
        for(int i=0; i<parent.size();i++){
            if(i==parent[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    int findParent(int u){
        if(parent[u]==u)    return u;
        return parent[u] = findParent(parent[u]);
    }

    void Union(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        //if they belong to the same component then return
        if(pu==pv)  return;
        //Always connect the smaller rank to the bigger rank, If the Ranks are same then connect any but here increase the rank of the one connecting to
        if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
  public:
  
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        // code here
        DSU disjointSet(v);
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            disjointSet.Union(a,b);
        }
        
        for(int i=0; i<v; i++){
            int par = disjointSet.findParent(i);
            mp[par].push_back(i);
        }
        
        for(auto it:mp){
            auto vec = it.second;
            ans.push_back(vec);
        }
        return ans;
    }
};
