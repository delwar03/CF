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
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin>>n>>q;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<vector<int>> cur(BLK + 10);
    vector<int> lz(BLK + 10, -1);

    for(int i = 0; i < n; i++) {
        cur[i / BLK].push_back(b[i]);
    }

    auto push = [&] (int b) {
        if(lz[b] == -1) return;

        int id = lz[b];

        for(int i = 0; i < BLK; i++) {
            cur[b][i] = a[id + i];
        }

        lz[b] = -1;
    };

    auto upd = [&] (int x, int y, int k) {
        int L = y / BLK, R = (y + k - 1) / BLK;
        int lb = y % BLK, rb = (y + k - 1) % BLK;
        if(L == R) {
            push(L);
            for(int i = lb; i <= rb; i++) {
                cur[L][i] = a[x + i - lb];
            }
        } else {
            push(L);
            for(int i = lb; i < BLK; i++) {
                cur[L][i] = a[x + i - lb];
            } // x + BLK - lb

            int tmp = x + BLK - lb;
            for(int i = L + 1; i < R; i++) {
                lz[i] = tmp;
                tmp += BLK;
            }

            push(R);
            for(int i = 0; i <= rb; i++) {
                cur[R][i] = a[tmp + i];
            }
        }
    };

    auto qur = [&] (int x) {
        int L = x / BLK, lb = x % BLK;
        push(L);
        return cur[L][lb];
    };

    while(q--) {
        int ty; cin>>ty;
        if(ty == 1) {
            int x, y, k; cin>>x>>y>>k;
            --x; --y;
            upd(x, y, k);
        } else {
            int x; cin>>x;
            --x;
            cout<<qur(x)<<endl;
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