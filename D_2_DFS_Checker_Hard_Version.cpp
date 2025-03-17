#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> par(n + 1, -1), perm(n + 1, 0);
    vector<set<int>> st(n + 1);
    vector<int> g[n + 1];
    map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        cin>>par[i];
        g[par[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin>>perm[i];
        mp[perm[i]] = i;
    }
 
    int bad = 0;
    vector<int> sz(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        sz[u] = 1;
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
                sz[u] += sz[v];
            }
        }
    };

    dfs(1, 0);
 
    auto isPossible = [&] (int i) {
        if (!st[i].size()) return false;
        int x = mp[i];
        int y = *st[i].begin();
        return (y < x);
    };
 
    auto del = [&](int i, int x) {
        auto it = st[i].find(x);
        int l = -1, r = -1;
 
        if (it != st[i].begin()) {
            l = *prev(it);
            if (l + sz[perm[l]] != x) bad--;
        }
        if (next(it) != st[i].end()) {
            r = *next(it);
            if (x + sz[perm[x]] != r) bad--;
        }

        if (l != -1 && r != -1) {
            if (l + sz[perm[l]] != r) bad++;
        }
        st[i].erase(it);
    };
 
    auto add = [&](int i, int x) {
        st[i].insert(x);
        auto it = st[i].find(x);
        int l = -1, r = -1;

        if (it != st[i].begin()) {
            l = *prev(it);
            if (l + sz[perm[l]] != x) bad++;
        }
 
        if (next(it) != st[i].end()) {
            r = *next(it);
            if (x + sz[perm[x]] != r) bad++;
        }
 
        if (l != -1 && r != -1) {
            if (l + sz[perm[l]] != r) bad--;
        }
    };
    for (int i = 1; i <= n; i++) {
        if (par[perm[i]] != -1) add(par[perm[i]], i);
    }
    for (int i = 1; i <= n; i++) bad += isPossible(i);

    while (q--) {
        int x, y; cin>>x>>y;
        set<int> tmp;
        tmp.insert(perm[x]);
        tmp.insert(perm[y]);
        tmp.insert(par[perm[x]]);
        tmp.insert(par[perm[y]]);
        for (int it : tmp) {
            if(it == -1) continue;
            bad -= isPossible(it);
        }
        if (par[perm[x]] != -1) del(par[perm[x]], x);
        if (par[perm[y]] != -1) del(par[perm[y]], y);
        swap(perm[x], perm[y]);
        swap(mp[perm[x]], mp[perm[y]]);

        if (par[perm[x]] != -1) add(par[perm[x]], x);
        if (par[perm[y]] != -1) add(par[perm[y]], y);
            
        for (int it : tmp) {
            if(it == -1) continue;
            bad += isPossible(it);
        }
        cout<<(bad == 0 ? "YES": "NO")<<endl;;
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