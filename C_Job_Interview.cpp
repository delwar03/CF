#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    int sz = n + m + 1;
    vector<int> p(sz), t(sz);
    for(auto &x : p) cin>>x;
    for(auto &x : t) cin>>x;

    vector<vector<int>> prog, test;

    for(int i = 0; i < sz; i++) {
        if(p[i] > t[i]) {
            prog.push_back({p[i], t[i], i});
        } else {
            test.push_back({t[i], p[i], i});
        }
    }
    if(prog.size() <= n) {
        swap(prog, test);
        swap(n, m);
    }

    while(prog.size() > n + 1) {
        auto vec = prog.back(); prog.pop_back();
        test.push_back({vec[1], vec[0], vec[2]});
    }

    int tot = 0;
    for(auto x : prog) tot += x[0];
    for(auto x : test) tot += x[0];
    
    vector<int> ans(sz);

    for(auto x : prog) ans[x[2]] = tot - x[0];
    for(auto x : test) ans[x[2]] = tot - x[0] - prog.back()[0] + prog.back()[1];
    
    for(auto it : ans) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 