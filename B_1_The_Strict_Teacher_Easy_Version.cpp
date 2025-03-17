#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m, q; cin>>n>>m>>q;
    vector<int> v(m);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());

    while(q--) {
        int ind; cin>>ind;
        if(ind > v[1]) {
            cout<<n - v[1]<<endl;
        } else if(ind < v[0]) {
            cout<<v[0] - 1<<endl;
        } else {
            cout<<(v[1] - v[0]) / 2<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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