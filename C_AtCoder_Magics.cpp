#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> vals;

void solve() {
    int n; cin>>n;
    vector<array<int, 2>> v(n);
    for(auto &[x, y] : v) {
        cin>>x>>y;
        vals.push_back(x);
        vals.push_back(y);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto getId = [&] (int x) {
        int ind = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        return ind;
    };

    for(auto &[x, y] : v) {
        x = getId(x);
        y = getId(y);
    }

    int sz = 8 * n;
    vector<int> Seg(2 * sz + 10, INF);

    auto upd = [&] (int i, int x) {
        for(Seg[i += sz] = x, i >>= 1; i; i >>= 1) Seg[i] = min(Seg[2 * i], Seg[2 * i + 1]);
    };

    auto qur = [&] (int l, int r) {
        int ret = INF;
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ret = min(ret, Seg[l++]);
            if(!(r & 1)) ret = min(ret, Seg[r--]);
        }
        return ret;
    };

    for(auto [a, c] : v) upd(a, c);

    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++) {
        int a = v[i][0], c = v[i][1];
        int mn = qur(a + 1, sz);
        if(mn < c) vis[i] = 1;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) ans.push_back(i + 1);
    }

    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it<<" ";
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