#include<vector>
#include<iostream>
using namespace std;
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
int main(){
    int n,m,q;
    cout<<"Enter the number of Nodes, Edges and Queries:"<<endl;
    cin >> n >> m >> q;
    vector<string> ans(q);
    DSU dsu(n);
    cout<<"Enter the Edges"<<endl;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        dsu.Union(a,b);
    }
    cout<<"Enter the Queries"<<endl;
    for(int i=0; i<q; i++){
        int a,b;
        cin >> a >> b;
        ans[i] = (dsu.findParent(a)==dsu.findParent(b)?"True":"False");
    }

    for(int i=0; i<q; i++){
        cout<<ans[i]<<" ";
    }
};