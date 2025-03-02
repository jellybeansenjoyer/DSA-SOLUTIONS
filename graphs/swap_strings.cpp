
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans = "";
        int len = s.length();
        DSU dsu(len);

        for(int i=0; i<pairs.size(); i++){
            dsu.Union(pairs[i][0],pairs[i][1]);
        } 

        unordered_map<int,vector<char>> mp;
        for(int i=0; i<len; i++){
            int par = dsu.findParent(i);
            mp[par].push_back(s[i]);
        }

        

        // //sorting in descending order
        for(auto it: mp){
            auto vec = it.second;
            sort(vec.begin(),vec.end(),greater<char>());
            mp[it.first] = vec;
           
        }

        for(int i=0; i<len; i++){
            int par = dsu.findParent(i);
            if(!mp[par].empty()){
                int letter = mp[par].back();
                ans+=letter;
                mp[par].pop_back();
            }
        }
        return ans;
    }
};