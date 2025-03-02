#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void input_graph(int V,int E,int D,unordered_map<int,vector<int> > &mp){
    int a,b;
    for(int i = 0;i<E;i++){
        cin>>a>>b;
        mp[a].push_back(b);
        if(!D){
            mp[b].push_back(a);
        }
    }
}

void print_graph(unordered_map<int,vector<int> > mp){
    for(auto it:mp){
        cout<<it.first<<"->";
        for(int i=0;i<it.second.size();i++){
            cout<<it.second[i];
            if(i!=it.second.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
    }
}
int main(){
    int V,E,D;
    cout<<"Enter the number of Vertices and Edges of the graph"<<endl;
    unordered_map<int,vector<int> > mp;
    cin>>V>>E;
    cout<<"check 1->directed and 0->undirected"<<endl;
    cin>>D;
    input_graph(V,E,D,mp);
    print_graph(mp);
}