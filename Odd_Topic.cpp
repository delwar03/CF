#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
#define Mat array<bitset<M>, N>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 4e3 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

Mat bst1, bst2;

void solve() {
    int n, m, q; cin>>n>>m>>q;
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    for(int i = 0; i < n; i++) {
        if(i) bst1[i] = bst1[i - 1];
        if(bst1[i][a[i]]) {
            bst1[i][a[i]] = 0;
        } else {
            bst1[i][a[i]] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        if(i) bst2[i] = bst2[i - 1];
        if(bst2[i][b[i]]) {
            bst2[i][b[i]] = 0;
        } else {
            bst2[i][b[i]] = 1;
        }
    }

    while(q--) {
        int l1, r1, l2, r2; cin>>l1>>r1>>l2>>r2;
        --l1; --r1; --l2; --r2;
        int ans = 0;
        for(int i = 0; i < M; i++) {
            bool cur = bst1[r1][i];
            if(l1) cur ^= bst1[l1 - 1][i];
            cur ^= bst2[r2][i];
            if(l2) cur ^= bst2[l2 - 1][i];
            ans += cur;
        }
        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/