#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, s, m; cin>>n>>s>>m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int l, r; cin>>l>>r;
        v.push_back({l, r});
    }

    int mx = 0, prv = 0;

    // for(int i = 0; i < n; i++) cerr<<v[i][0]<<" "<<v[i][1]<<endl;

    for(int i = 0; i < n; i++) {
        mx = max(mx, v[i][0] - prv);
        prv = v[i][1];
    }

    mx = max(mx, m - prv);

    cout<<(mx >= s ? "YES" : "NO")<<endl;
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