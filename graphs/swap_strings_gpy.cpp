class DSU{
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]); // Path compression
    }

    void Union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.length();
        DSU dsu(len);

        // Union all pairs
        for(auto& p : pairs){
            dsu.Union(p[0], p[1]);
        }

        // Group characters by connected component
        unordered_map<int, vector<char>> mp;
        for(int i = 0; i < len; i++){
            int par = dsu.findParent(i);
            mp[par].push_back(s[i]);
        }

        // Sort characters in each component (ascending order)
        for(auto& it : mp){
            sort(it.second.begin(), it.second.end());
        }

        // Construct the final answer
        string ans = s;
        unordered_map<int, int> indexTracker; // Track which character to use next
        for(int i = 0; i < len; i++){
            int par = dsu.findParent(i);
            ans[i] = mp[par][indexTracker[par]++];
        }

        return ans;
    }
};
