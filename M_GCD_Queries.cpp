#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int spf[N];

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    map<int, multiset<int>> mp;
    multiset<int> all(v.begin(), v.end());
    for(int x : v) {
        int cur = x;
        while(cur > 1) {
            int p = spf[cur];
            mp[p].insert(x);
            while(cur % p == 0) cur /= p;
        }
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        int cur = x, ans = INF;
        while(cur > 1) {
            int p = spf[cur];
            if(mp.count(p)) ans = min(ans, *mp[p].begin());
            while(cur % p == 0) cur /= p;
        }
        if(ans == INF) {
            ans = *all.begin();
        }
        cout << ans << " \n"[q == 0];
        all.erase(all.find(ans));
        cur = ans;
        while(cur > 1) {
            int p = spf[cur];
            mp[p].erase(mp[p].find(ans));
            if(mp[p].empty()) mp.erase(p);
            while(cur % p == 0) cur /= p;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(spf[i]) continue;
        for(int j = i; j < N; j += i) {
            if(!spf[j]) spf[j] = i;
        }
    }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}