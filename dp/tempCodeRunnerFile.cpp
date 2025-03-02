f(n<=1) return n;
    int prev = 1;
    int prev2 = 0;
    vector<int> ans(n);
    ans.push_back(prev);
    ans.push_back(prev2);
    for(int i=2; i<=n; i++){
        cur = prev +prev2;
        ans.push_back(cur);
        prev2 = prev;
        prev = cur;
    }
    for(int i=0; i<=n; i++){
        cout<<ans[i]<<endl;
    }