#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e4 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bitset<N> on;

void solve() {
    int n, m, q; cin>>n>>m>>q;
    unordered_set<int> g[n + 1];
    vector<int> val(n + 1);
    int o; cin>>o;
    while(o--) {
        int u; cin>>u;
        on[u] = 1;
    }

    auto add_edge = [&] (int u, int v) {
        if(g[u].size() > g[v].size()) swap(u, v);
        g[u].insert(v);
        val[v] += on[u];
    };

    auto del_edge = [&] (int u, int v) {
        if(!g[u].count(v)) swap(u, v);
        g[u].erase(v);
        val[v] -= on[u];
    };

    auto upd = [&] (int u, int f) {
        on[u] = f;
        for(auto v : g[u]) val[v] += f - !f;
    };

    auto qur = [&] (int u) {
        int ret = val[u];
        for(auto v : g[u]) ret += on[v];
        return ret;
    };

    while(m--) {
        int u, v; cin>>u>>v;
        add_edge(u, v);
    }

    while(q--) {
        char ty; cin>>ty;
        if(ty == 'A' || ty == 'D') {
            int u, v; cin>>u>>v;
            if(ty == 'A')
                add_edge(u, v);
            else
                del_edge(u, v);
        } else if(ty == 'O' || ty == 'F') {
            int u; cin>>u;
            upd(u, ty == 'O');
        } else {
            int u; cin>>u;
            cout<<qur(u)<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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