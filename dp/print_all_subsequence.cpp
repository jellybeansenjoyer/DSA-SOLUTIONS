#include<bits/stdc++.h>
using namespace std;
void solve(vector<string> &ans,string s,int i,string temp){
    if(i>=s.length()){
        ans.push_back(temp);
        return;
    }
    solve(ans,s,i+1,temp+s[i]);
    solve(ans,s,i+1,temp);
}
vector<string> AllPossibleStrings(string s){
 // Code here
 string tmp = "";
 vector<string> ans;
 solve(ans,s,0,tmp);
 sort(ans.begin(),ans.end());
 return ans;
}