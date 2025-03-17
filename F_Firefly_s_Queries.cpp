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
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    for(int i = 0; i < n; i++) v.push_back(v[i]);

    vector<int> pf(2 * n + 5);

    for(int i = 1; i < 2 * n; i++) pf[i] = pf[i - 1] + v[i - 1];

    auto query = [&] (int ind) {
        int L = ind / n;
        int res = L * pf[n];
        ind %= n;
        res += pf[L + ind] - pf[L];
        return res;
    };

    while(q--) {
        int l, r; cin>>l>>r;
        cout<<query(r) - query(l - 1)<<endl;
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