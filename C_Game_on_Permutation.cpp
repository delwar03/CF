#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

class DisjointSet {
    
public:
    vector<int> rank, parent, sz;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }

    void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
};

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    n++;
    int dp[n];
    memset(dp, -1, sizeof dp);
    dp[v[0]] = 0;
    int base = 1;
    while(base <= (2 * n)) base *= 2;
    vector<int> seg(2 * base + 1);

    auto build = [&] {
        for(int i = 0; i < n; i++) {
            seg[i + n] = dp[i];
        }
        for(int i = n - 1; i >= 1; i--) {
            seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        }
    };

    auto update = [&] (int i, int v) {
        i += n;
        seg[i] = v;
        while(i > 1) {
            i >>= 1;
            seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        }
    };

    auto query = [&] (int l, int r) {
        l += n;
        r += n;
        int mx = -1;
        while(l <= r) {
            if(l & 1) {
                mx = max(mx, seg[l++]);
            }
            if(!(r & 1)) {
                mx = max(mx, seg[r--]);
            }
            l >>= 1;
            r >>= 1;
        }
        return mx;
    };

    build();

    for(int i = 1; i < n - 1; i++) {
        int q = query(0, v[i] - 1);
        update(v[i], 1 + q);
    }

    int ans = 0;

    // for(int i = 0; i < n; i++) cerr<<query(i, i)<<" "; cerr<<endl;

    for(int i = 0; i < n; i++) {
        if(query(i, i) == 1) {
            ans++;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/