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

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    vector<int> nxt(n + 1), cnt(n + 1);

    auto upd = [&] (int ind) {
        int par = ind + v[ind];
        nxt[ind] = ind;
        cnt[ind] = 0;
        if(par <= n && (ind / BLK) == (par / BLK)) {
            cnt[ind] = 1 + cnt[par];
            nxt[ind] = nxt[par];
        }
    };

    auto qur = [&] (int ind) {
        int ret = 0, tmp = ind, lst = ind;
        while(tmp <= n) {
            ret += cnt[tmp];
            tmp = nxt[tmp];
            lst = tmp;
            
            tmp = tmp + v[tmp];
            ret++;
        }
        return make_pair(lst, ret);
    };

    for(int i = n; i; i--) upd(i);

    // for(int i = 1; i <= n; i++) cerr<<nxt[i]<<" "; cerr<<endl;

    while(q--) {
        int t; cin>>t;
        if(t == 1) {
            int ind; cin>>ind;
            auto ans = qur(ind);
            cout<<ans.F<<" "<<ans.S<<endl;
        } else {
            int ind, val; cin>>ind>>val;
            v[ind] = val;
            int blkNo = ind / BLK, last = min(n, blkNo * BLK + BLK - 1);
            for(int i = last; (i / BLK) == blkNo && i; i--) upd(i);
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