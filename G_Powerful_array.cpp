#include <bits/stdc++.h>
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

struct Query {
    int l, r, idx;
};

vector<int> freq(N);
int cur;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<Query> que(q);

    for(int i = 0; i < q; i++) {
        cin>>que[i].l>>que[i].r;
        que[i].l--; que[i].r--;
        que[i].idx = i;
    }

    sort(que.begin(), que.end(), [&] (Query a, Query b) {
        if(a.l / BLK != b.l / BLK) return a.l / BLK < b.l / BLK;
        return ((a.l / BLK) & 1) ? a.r < b.r : a.r > b.r;
    });

    auto upd = [&] (int x, int delta) {
        cur -= freq[x] * freq[x] * x;
        freq[x] += delta;
        cur += freq[x] * freq[x] * x;
    };

    vector<int> ans(q);
    int lb = 0, rb = -1;

    for(int i = 0; i < q; i++) {
        int l = que[i].l, r = que[i].r, idx = que[i].idx;

        while(rb < r) upd(v[++rb], +1);
        while(lb > l) upd(v[--lb], +1);

        while(rb > r) upd(v[rb--], -1);
        while(lb < l) upd(v[lb++], -1);

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