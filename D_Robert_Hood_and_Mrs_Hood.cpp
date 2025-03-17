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
    int n, d, k; cin>>n>>d>>k;
    vector<int> pf(n);
    while(k--) {
        int l, r; cin>>l>>r;
        --l; --r;
        l = max(0LL, l - d + 1);
        pf[l] += 1;
        if(r + 1 < n)
            pf[r + 1] -= 1;
    }

    for(int i = 1; i < n; i++) pf[i] += pf[i - 1];

    // cerr<<"pf: ";
    // for(auto it : pf) cerr<<it<<" "; cerr<<endl;

    int cnt = 0, mx = 0, mn = INF, indMx = 1, indMn = 1;

    for(int i = 0; i <= n - d; i++) {
        if(pf[i] > mx) {
            mx = pf[i];
            indMx = i + 1;
        }
        if(pf[i] < mn) {
            mn = pf[i];
            indMn = i + 1;
        }
    }

    cout<<indMx<<" "<<indMn<<endl;
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