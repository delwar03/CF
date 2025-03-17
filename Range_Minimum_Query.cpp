#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> pre(BLK, INF);

    for(int i = 0; i < n; i++) {
        pre[i / BLK] = min(pre[i / BLK], v[i]);
    }

    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        int ans = INF;

        while(l <= r) {
            if(l % BLK == 0 && l + BLK - 1 <= r) {
                ans = min(ans, pre[l / BLK]);
                l += BLK;
            } else {
                ans = min(ans, v[l]);
                l++;
            }
        }

        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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