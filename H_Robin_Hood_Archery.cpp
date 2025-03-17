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
const int N = 1e6 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> freq(N);
int cur;

struct Query {
    int l, r, idx;
    bool operator < (const Query &q) const {
        if(l / BLK != q.l / BLK) return l / BLK < q.l / BLK;
        return ((l / BLK) & 1) ? r < q.r : r > q.r;
    }
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    int mx = 0;
    for(auto &x : v) {cin>>x; mx = max(mx, x);}
    vector<Query> que(q);
    for(int i = 0; i < q; i++) {
        cin>>que[i].l>>que[i].r;
        que[i].l--; que[i].r--;
        que[i].idx = i;
    }

    sort(que.begin(), que.end());

    auto upd = [&] (int i, int delta) {
        cur -= (freq[v[i]] & 1);
        freq[v[i]] += delta;
        cur += (freq[v[i]] & 1);
    };

    vector<int> ans(q);
    int lb = 0, rb = -1;
    cur = 0;
    freq.assign(mx + 1, 0);

    for(int i = 0; i < q; i++) {
        int l = que[i].l, r = que[i].r, idx = que[i].idx;

        while(rb < r) upd(++rb, +1);
        while(lb > l) upd(--lb, +1);

        while(rb > r) upd(rb--, -1);
        while(lb < l) upd(lb++, -1);

        ans[idx] = cur;
    }

    for(int i = 0; i < q; i++) {
        cout<<(!ans[i] ? "YES" : "NO")<<endl;
    }
    // cout<<"HI"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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