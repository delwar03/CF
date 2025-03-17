#include <bits/stdc++.h>
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
};

// pf[r] - pf[l] = k
// pf[l] = pf[r] - k

// pf[r] - pf[l] = k
// pf[r] = pf[l] + k

map<int, int> mp;
int cur;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> type(n), val(n);
    for(auto &x : type) cin>>x;
    for(auto &x : val) cin>>x;

    for(int i = 0; i < n; i++) {
        if(type[i] == 2) {
            val[i] = -val[i];
        }
    }

    vector<int> pf(n + 1);

    for(int i = 0; i < n; i++) pf[i + 1] = pf[i] + val[i];

    for(int i = 0; i <= n; i++) {
        mp[pf[i]]; mp[pf[i] - k]; mp[pf[i] + k];
    }

    int id = 0;
    for(auto &it : mp) {
        it.S = ++id;
    }

    vector<int> pf_ind(n + 1), plus(n + 1), minus(n + 1);

    for(int i = 0; i <= n; i++) {
        pf_ind[i] = mp[pf[i]];
        plus[i] = mp[pf[i] + k];
        minus[i] = mp[pf[i] - k];
    }

    int q; cin>>q;
    vector<Query> que(q);

    for(int i = 0; i < q; i++) {
        cin>>que[i].l>>que[i].r;
        --que[i].l;
        que[i].idx = i;
    }

    sort(que.begin(), que.end(), [&] (Query a, Query b) {
        if(a.l / BLK != b.l / BLK) return a.l / BLK < b.l / BLK;
        return ((a.l / BLK) & 1) ? a.r < b.r : a.r > b.r;
    });

    vector<int> ans(q), freq(3 * n + 5);
    int lb = 0, rb = -1;

    auto upd = [&] (int i, int delta, int f) {
        if(delta == 1) {
            if(f) {
                cur += freq[plus[i]];
            } else {
                cur += freq[minus[i]];
            }
            freq[pf_ind[i]] += delta;
        } else {
            freq[pf_ind[i]] += delta;
            if(f) {
                cur -= freq[plus[i]];
            } else {
                cur -= freq[minus[i]];
            }
        }
    };

    for(int i = 0; i < q; i++) {
        int l = que[i].l, r = que[i].r, idx = que[i].idx;

        while(rb < r) upd(++rb, +1, 0);
        while(lb > l) upd(--lb, +1, 1);

        while(rb > r) upd(rb--, -1, 0);
        while(lb < l) upd(lb++, -1, 1);

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