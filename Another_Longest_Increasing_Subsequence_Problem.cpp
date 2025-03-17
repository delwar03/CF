#include <bits/stdc++.h>
#define int long long
#define ll long long
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
    vector<pair<int, int>> v(n);
    for(auto &x : v) cin>>x.F>>x.S;

    sort(v.begin(), v.end());

    vector<pair<int, int>> Y;
    for(int i = 0; i < n; i++) {
        Y.push_back({v[i].S, i});
    }

    vector<pair<int, int>> dp(n + 1, {INF, INF});
    vector<int> par(n + 1, -1);

    for(int i = 0; i < n; i++) {
        auto it = upper_bound(dp.begin(), dp.end(), Y[i]);
        *it = Y[i];
        if(it != dp.begin()) {
            par[i] = prev(it)->S;
        }
    }

    int ans = lower_bound(dp.begin(), dp.end(), make_pair(INF, INF)) - dp.begin();

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