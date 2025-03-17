#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, a, b; cin>>n>>a>>b;
    vector<int> v(n);
    int g = __gcd(a, b);
    for(auto &x : v) {cin>>x; x %= g; }
    sort(v.begin(), v.end());
    int ans = INF, mx = v[n - 1];

    for(int i = 0; i < n; i++) {
        ans = min(ans, mx - v[i]);
        mx = max(mx, v[i] + g);
    }
    cout<<ans<<endl;
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