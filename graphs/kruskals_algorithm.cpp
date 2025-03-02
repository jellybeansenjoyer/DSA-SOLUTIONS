#include<vector>
#include<iostream>
using namespace std;
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int findParent(int u,vector<int> &par){
        if(u==par[u])   return u;
        return par[u] = findParent(par[u],par);
    }
    void union_(int u,int v,vector<int> &rank1,vector<int> &par){
        int pu = findParent(u,par);
        int pv = findParent(v,par);
        if(pu==pv)  return;
        if(rank1[pu]<rank1[pv]){
            par[pu] = pv;
        }else if(rank1[pv]<rank1[pu]){
            par[pv] = pu;
        }else{
            par[pv] = pu;
            rank1[pu]++;
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<int> rank1(V,0);
        vector<int> par(V);
        int ans=0;
        for(int i=0; i<V; i++){
            par[i] = i;
        }
        
        vector<pair<int,pair<int,int>>> lst;
        for(int u=0; u<V; u++){
            for(auto child: adj[u]){
                int v = child[0];
                int w = child[1];
                lst.push_back({w,{u,v}});
            }
        }
        sort(lst.begin(),lst.end());
        
        for(int i=0; i<lst.size(); i++){
            int w = lst[i].first;
            int u = lst[i].second.first;
            int v = lst[i].second.second;
            if(findParent(u,par)!=findParent(v,par)){
                union_(u,v,rank1,par);
                ans+=w;
            }
        }
        return ans;
    }
};