#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> pf(n + 1), pref_mx(n + 1);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] + v[i];
        pref_mx[i + 1] = max(pref_mx[i], v[i]);
    }
    // cerr<<"pf: ";
    // for(auto it : pf) cerr<<it<<" "; cerr<<endl;

    while(q--) {
        int k; cin>>k;
        int ind = upper_bound(pref_mx.begin(), pref_mx.end(), k) - pref_mx.begin();
        
        cout<<pf[--ind]<<" \n"[q == 0];
    }
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