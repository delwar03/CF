#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> pref(n + 1), suff(n + 1);
    set<int> st;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        st.insert(v[i - 1]);
        sum += v[i - 1];
        if(st.size() == i && sum == i * (i + 1) / 2) pref[i] = 1;
    }
    sum = 0;
    st.clear();
    for(int i = n; i >= 1; i--) {
        st.insert(v[i - 1]);
        sum += v[i - 1];
        int p = n - i + 1;
        if(st.size() == p && sum == p * (p + 1) / 2) suff[i] = 1;
    }
    // cerr<<"pref: ";
    // for(auto it : pref) cerr<<it<<" "; cerr<<endl;
    // cerr<<"suff: ";
    // for(auto it : suff) cerr<<it<<" "; cerr<<endl;
    vector<vector<int>> ans;
    for(int i = 1; i < n; i++) {
        if(pref[i] && suff[i + 1]) ans.push_back({i, n - i});
    }
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it[0]<<" "<<it[1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 