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
    int n, m; cin>>n>>m;
    vector<int> col(n);
    iota(col.begin(), col.end(), 1LL);

    vector<vector<int>> cur(BLK + 10), val(BLK + 10);
    vector<int> lz_col(BLK + 10), lz_val(BLK + 10), sm(BLK + 10);

    for(int i = 0; i < n; i++) {
        cur[i / BLK].push_back(col[i]);
        val[i / BLK].push_back(0);
    }

    auto push = [&] (int b) {
        if(!lz_col[b]) return;
        for(int i = 0; i < BLK; i++) {
            cur[b][i] = lz_col[b];
            val[b][i] += lz_val[b];
        }
        lz_col[b] = lz_val[b] = 0;
    };

    auto upd = [&] (int l, int r, int x) {
        int L = l / BLK, R = r / BLK;
        int lb = l % BLK, rb = r % BLK;
        if (L == R) {
            push(L);
            for (int i = lb; i <= rb; i++) {
                int add = abs(cur[L][i] - x);
                cur[L][i] = x;
                val[L][i] += add;
                sm[L] += add;
            }
        } else {
            push(L);
            for (int i = lb; i < BLK; i++) {
                int add = abs(cur[L][i] - x);
                cur[L][i] = x;
                val[L][i] += add;
                sm[L] += add;
            }

            for(int i = L + 1; i < R; i++) {
                if(lz_col[i]) {
                    int add = abs(lz_col[i] - x);
                    lz_val[i] += add;
                    sm[i] += add * BLK;
                } else {
                    for(int j = 0; j < BLK; j++) {
                        int add = abs(cur[i][j] - x);
                        cur[i][j] = x;
                        val[i][j] += add;
                        sm[i] += add;
                    }
                }
                lz_col[i] = x;
            }

            push(R);
            for(int i = 0; i <= rb; i++) {
                int add = abs(cur[R][i] - x);
                cur[R][i] = x;
                val[R][i] += add;
                sm[R] += add;
            }
        }
    };

    auto qur = [&] (int l, int r) {
        int L = l / BLK, R = r / BLK;
        int lb = l % BLK, rb = r % BLK, ret = 0;
        if (L == R) {
            push(L);
            for(int i = lb; i <= rb; i++) {
                ret += val[L][i];
            }
        } else {
            push(L);
            for(int i = lb; i < BLK; i++) {
                ret += val[L][i];
            }

            for(int i = L + 1; i < R; i++) {
                ret += sm[i];
            }

            push(R);
            for(int i = 0; i <= rb; i++) {
                ret += val[R][i];
            }
        }
        return ret;
    };

    while(m--) {
        int ty; cin>>ty;
        if(ty == 1) {
            int l, r, x; cin>>l>>r>>x;
            --l; --r;
            upd(l, r, x);
        } else {
            int l, r; cin>>l>>r;
            --l; --r;
            cout<<qur(l, r)<<endl;
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