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
    int n, t; cin>>n>>t;
    string s; cin>>s;
    vector<int> pos(n);
    for(auto &x : pos) cin>>x;

    vector<int> p[2];
    for(int i = 0; i < n; i++) {
        p[s[i] - '0'].push_back(pos[i]);
    }
    sort(p[0].begin(), p[0].end());
    sort(p[1].begin(), p[1].end());

    int ans = 0;
    for(auto x : p[1]) {
        int my = upper_bound(p[0].begin(), p[0].end(), x) - p[0].begin();
        int ind = upper_bound(p[0].begin(), p[0].end(), x + 2 * t) - p[0].begin();
        ans += ind - my;
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