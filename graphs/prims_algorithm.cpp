#include<vector>
#include<iostream>
#include<priority_queue>
#include<pair>
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int ans = 0;
        vector<int> vis(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int> node = pq.top();
            pq.pop();
            int w = node.first;
            int v = node.second;
            if(!vis[v]){
                for(auto child:adj[v]){
                    int child_v = child[0];
                    int child_w = child[1];
                    if(!vis[child_v])
                    pq.push({child_w,child_v});
                }
            }else{
                continue;
            }
            ans+=w;
            vis[v] = 1;
            
        }
        return ans;
    }
};