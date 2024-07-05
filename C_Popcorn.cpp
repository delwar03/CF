#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    int ans = n;
    int mask = 1LL << (n + 1);

    for(int i = 1; i < mask; i++) {
        set<int> ind;
        for(int j = 0; j < n; j++) {
            if(i & (1LL << j)) {
                for(int k = 0; k < m; k++) {
                    if(v[j][k] == 'o') {
                        ind.insert(k);
                    }
                }
            }
        }
        if(ind.size() == m) ans = min(ans, (int) __builtin_popcount(i));
    }
    cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/