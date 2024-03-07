#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m, x; cin>>n>>m>>x;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        v.push_back({x, i});
    }
    sort(v.rbegin(), v.rend());
    set<vector<int>> st;
    for(int i = 0; i < m; i++) {
        st.insert({0, i});
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        auto vec = (*st.begin());
        st.erase(st.begin());
        vec[0] += v[i][0];
        ans[v[i][1]] = vec[1];
        st.insert(vec);
    }
    if((*st.rbegin())[0] - (*st.begin())[0] > x) {
        cout<<"NO"<<endl;
        return;
    }
    for(auto it : st) {
        for(int i = 2; i < it.size(); i++) ans[it[i]] = it[1];
    }
    cout<<"YES"<<endl;
    for(auto it : ans) cout<<it + 1<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 