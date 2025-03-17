#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Query {
    int l, r, k, idx;
    vector<int> id;
    bool operator < (const Query &q) const {
        if(l / BLK != q.l / BLK) return l / BLK < q.l / BLK;
        return ((l / BLK) & 1) ? r < q.r : r > q.r;
    }
};

vector<int> freq(N);
int cur;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<Query> que(q);
    for(int i = 0; i < q; i++) {
        cin>>que[i].l>>que[i].r>>que[i].k;
        que[i].l--; que[i].r--;
        que[i].idx = i;
        for(int j = 0; j < 100; j++) {
            int rn = que[i].l + (rng() % (que[i].r - que[i].l + 1));
            que[i].id.push_back(rn);
        }
    }

    sort(que.begin(), que.end());

    auto upd = [&] (int i, int delta) {
        freq[v[i]] += delta;
    };

    vector<int> ans(q);
    int lb = 0, rb = -1;

    for(int i = 0; i < q; i++) {
        int l = que[i].l, r = que[i].r, k = que[i].k, idx = que[i].idx;

        while(rb < r) upd(++rb, +1);
        while(lb > l) upd(--lb, +1);

        while(rb > r) upd(rb--, -1);
        while(lb < l) upd(lb++, -1);

        cur = INF;
        int ct = (r - l + 1) / k;

        for(auto j : que[i].id) {
            if(freq[v[j]] > ct) {
                cur = min(cur, v[j]);
            } 
        }

        if(cur == INF) cur = -1;
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