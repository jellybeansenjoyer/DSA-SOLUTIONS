
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int findParent(int par[],int x){
          if(par[x]==x){
              return par[x];
          }
          return par[x] = findParent(par,par[x]);
      }
      void unionByRank(int x,int y,int par[],int rank[]){
          int par_x = findParent(par,x);
          int par_y = findParent(par,y);
          if(rank[par_x]<rank[par_y]){
              par[par_x] = par_y;
          }else if(rank[par_x]>rank[par_y]){
              par[par_y] = par_x;
          }else{
              par[par_y] = par_x;
              rank[par_x]++;
          }
      }
      int spanningTree(int V, vector<vector<int>> adj[]) {
          // code here
          vector<pair<int,pair<int,int>>> vec;
          int rank[V];
          int parent[V];
          memset(rank,0,sizeof rank);
          for(int i=0;i<V;i++){
              parent[i] = i;
          }
          for(int u=0; u<V; u++){
              for(auto child: adj[u]){
                  int w = child[1];
                  int v = child[0];
                  vec.push_back({w,{u,v}});
              }
          }
          int ans = 0;
          sort(vec.begin(),vec.end());
          for(auto ele: vec){
              int w = ele.first;
              int u = ele.second.first;
              int v = ele.second.second;
              if(findParent(parent,u)!=findParent(parent,v)){
                  unionByRank(u,v,parent,rank);
                  ans+=w;
              }
          }
          return ans;
          
      }
  };