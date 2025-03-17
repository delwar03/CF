#include <bits/stdc++.h>
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
    int n; cin>>n;
    vector<int> v(n), w(n);
    for(auto &x : v) cin>>x;
    for(auto &x : w) cin>>x;

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[v[i]].push_back(w[i]);
    }

    int ans = 0;
    for(auto it : mp) {
        int mx = 0;
        for(auto x : it.S) {
            ans += x;
            mx = max(mx, x);
        }
        ans -= mx;
    }
    cout<<ans<<endl;
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