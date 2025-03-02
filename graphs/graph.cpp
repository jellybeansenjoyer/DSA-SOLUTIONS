#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<vector>
using namespace std;
class Graph{
    private:
        int vertices;
        int edges;
        bool directed;
        vector<int> vis;
        vector<int> dist;
        map<int , vector<int> > mp;
    public:
        int getVertices(){
            return vertices;
        }
        int getEdges(){
            return edges;
        }
        bool isDirected(){
            return directed;
        }
        void initVisited(){
            this->vis = vector<int>(this->vertices,0);
        }
        void initDistance(){
            this->dist = vector<int>(this->vertices,INT_MAX);
        }
        Graph(int v,int e,int d){
            this->vertices = v;
            this->edges = e;
            this->directed = d;
            initVisited();
            initDistance();
            cout<<"Enter the edges"<<endl;
            int a,b;
            for(int i = 0;i<this->edges;i++){
                cin>>a>>b;
                mp[a].push_back(b);
                if(!this->directed)
                    mp[b].push_back(a);
            }
        }
        void printGraph(){
            for(auto it:this->mp){
                cout<<it.first<<"-> ";
                for(int i = 0;i<it.second.size();i++){
                    cout<<it.second[i];
                    if(i<it.second.size()-1){
                        cout<<",";
                    }
                }
                cout<<endl;
            }
        }
        void dfs(int v,vector<int> &vis){
            vis[v] = 1;
            cout<<v<<",";
            for(auto it:mp[v]){
                if(!vis[it]){
                    dfs(it,vis);
                }
            }
        }
        void dfsFn(){
            cout<<"The DFS traversal is as follows:"<<endl;
            for(auto it:mp){
                if(!vis[it.first]){
                    dfs(it.first,vis);
                }
            }
        }
        void bfs(int src){
            queue<int> q;
            q.push(src);
            vis[src] = 1;
            while(!q.empty()){
                auto node = q.front();
                cout<<node<<",";
                q.pop();
                for(auto child:mp[node]){
                    if(!vis[child]){
                        vis[child] = 1;
                        q.push(child);
                    }
                }
            }
        }
        void bfsFn(){
            for(auto it:mp){
                if(!vis[it.first]){
                    bfs(it.first);
                }
            }
        }
};

int main(){
    int v,e,d;
    cout<<"Enter the V , E , D"<<endl;
    cin>>v>>e>>d;
    Graph g(v,e,d);
    g.printGraph();
    cout<<"DFS traversal:->"; 
    g.dfsFn();
    cout<<endl;
    cout<<"BFS traversal:->";
    g.initVisited();
    g.bfsFn();
    cout<<endl;
}