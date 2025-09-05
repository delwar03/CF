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
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    map<string, int> mp;
    vector<string> inv_mp;
    vector<pii> g[n];
    map<pii, vector<int>> inv_g;
    vector<int> cnt(n);
    int m = 0;
    for(int i = 0; i < n; i++) {
        int k; cin>>k;
        while(k--) {
            char sgn;
            string s; cin>>sgn>>s;
            if(!mp.count(s)) mp[s] = m++, inv_mp.push_back(s);
            g[i].push_back({mp[s], sgn == '+'});
            inv_g[{mp[s], sgn == '+'}].push_back(i);
            cnt[i] += (sgn == '-');
        }
    }

    vector<int> q, in(n), take(m);
    for(int i = 0; i < n; i++) if(3 * cnt[i] <= sz(g[i])) q.push_back(i), in[i] = 1;

    for(int i = 0; i < sz(q); i++) {
        int x = q[i];
        in[x] = 0;
        if(3 * cnt[x] > sz(g[x])) continue;
        auto cur = g[x][rng() % sz(g[x])];
        while(cur.S == take[cur.F]) cur = g[x][rng() % sz(g[x])];
        take[cur.F] = cur.S;
        for(int i : inv_g[cur]) cnt[i] += 1;
        if(3 * cnt[x] <= sz(g[x])) q.push_back(x), in[x] = 1;
        for(int i : inv_g[{cur.F, !cur.S}]) {
            cnt[i] -= 1;
            if(3 * cnt[i] <= sz(g[i]) && !in[i]) q.push_back(i), in[i] = 1;
        }
    }

    for(int i = 0; i < m; i++) if(take[i]) cout<<inv_mp[i]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}