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
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Query {
    int l, r, idx;
    bool operator < (const Query &q) const {
        if(l / BLK != q.l / BLK) return l / BLK < q.l / BLK;
        return ((l / BLK) & 1) ? r < q.r : r > q.r;
    }
};

vector<int> freq(N);
int cur;

void solve() {
    int n, q; cin>>n>>q;
    map<int, int> mp;
    vector<int> v(n);
    for(auto &x : v) {cin>>x; mp[x];}

    int id = 0;
    for(auto &it : mp) it.S = ++id;

    vector<int> val(n + 1);
    for(auto &it : mp) {
        val[it.S] = it.F;
    }
    for(auto &it : v) {
        it = mp[it];
    }

    vector<Query> que(q);
    for(int i = 0; i < q; i++) {
        cin>>que[i].l>>que[i].r;
        --que[i].l; --que[i].r;
        que[i].idx = i;
    }

    sort(que.begin(), que.end());

    auto upd = [&] (int i, int delta) {
        if(freq[v[i]] == val[v[i]]) cur--;
        freq[v[i]] += delta;
        if(freq[v[i]] == val[v[i]]) cur++;
    };

    vector<int> ans(q);
    int lb = 0, rb = -1;

    for(int i = 0; i < q; i++) {
        int l = que[i].l, r = que[i].r, idx = que[i].idx;

        while(rb < r) upd(++rb, +1);
        while(lb > l) upd(--lb, +1);

        while(rb > r) upd(rb--, -1);
        while(lb < l) upd(lb++, -1);

        ans[idx] = cur;
    }

    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
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