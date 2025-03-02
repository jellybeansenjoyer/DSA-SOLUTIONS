#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x[n];
    int y[n];
    int x1[] = {-1,0,1,0};
    int y1[] = {0,1,0,-1};
    for(int i=0; i<n;i++){
        cin>>x[i];
    }
    for(int j=0;j<n;j++){
        cin>>y[j];
    }

    unordered_set<pair<int,int>> st;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        v.push_back({x[i],y[i]});
        st.insert({x[i],y[i]});
    }
    int ans = 0;
    for(auto ele:v){
        int cnt =0;
        for(int i=0;i<4;i++){
            if(st.find({ele.first+x1[i],ele.second+y1[i]}))
            cnt++;
        }
        if(cnt==4){
            ans++;
        }
    }
    return ans;
}