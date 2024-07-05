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
    int n; cin>>n;
    vector<vector<int>> v;
    int cost = 0, tot = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        tot += x;
        cost += 2 * x;
        v.push_back({y, x}); // {b, a}
    }
    sort(v.rbegin(), v.rend());

    // tot = sum of ai
    
    for(int i = 0; i < n; i++) {
        if(tot < v[i][0]) continue;
        int now = tot - v[i][0];
        cost -= min(now, v[i][1]);
        tot -= min(now, v[i][1]);
    }
    cout<<cost<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 