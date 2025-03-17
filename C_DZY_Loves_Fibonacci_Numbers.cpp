#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 9;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> fib(N), pf(N);

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto add = [&] (int a, int b) {
        a += b;
        return a > mod ? a - mod : a;
    };

    auto sub = [&] (int a, int b) {
        a -= b;
        return a < 0 ? a + mod : a;
    };

    vector<vector<int>> cur(BLK + 10);
    vector<int> sm(BLK + 10);
    vector<array<int, 2>> lz(BLK + 10, {0, 0});

    for(int i = 0; i < n; i++) {
        cur[i / BLK].push_back(v[i]);
        sm[i / BLK] = add(sm[i / BLK], v[i]);
    }

    auto upd = [&] (int l, int r) {
        int L = l / BLK, R = r / BLK;
        int lb = l % BLK, rb = r % BLK;
        if(L == R) {
            for(int i = lb; i <= rb; i++) {
                cur[L][i] = add(cur[L][i], fib[i - lb]);
                sm[L] = add(sm[L], fib[i - lb]);
            }
        } else {
            for(int i = lb; i < (int) cur[L].size(); i++) {
                cur[L][i] = add(cur[L][i], fib[i - lb]);
                sm[L] = add(sm[L], fib[i - lb]);
            }

            int tmp = (int) cur[L].size() - lb;

            for(int i = L + 1; i < R; i++) {
                int curSm = sub(pf[tmp + BLK - 1], (tmp - 1 >= 0 ? pf[tmp - 1] : 0LL));
                sm[i] = add(sm[i], curSm);
                cur[i][0] = add(cur[i][0], fib[tmp]);
                cur[i][1] = add(cur[i][1], fib[tmp + 1]);
                lz[i][0] = add(lz[i][0], fib[tmp]);
                lz[i][1] = add(lz[i][1], fib[tmp + 1]);
                tmp += BLK;
            }

            for(int i = 0; i <= rb; i++) {
                cur[R][i] = add(cur[R][i], fib[tmp + i]);
                sm[R] = add(sm[R], fib[tmp + i]);
            }
        }
    };

    auto qur = [&] (int l, int r) {
        int L = l / BLK, R = r / BLK, ret = 0;
        int lb = l % BLK, rb = r % BLK;

        if(L == R) {
            int a = lz[L][0], b = lz[L][1];
            lz[L][0] = lz[L][1] = 0;
            if(a + b) {
                for(int i = 2; i < (int) cur[L].size(); i++) {
                    cur[L][i] = add(cur[L][i], add(a, b));
                    swap(a, b);
                    b = add(a, b);
                }
            }

            for(int i = lb; i <= rb; i++) {
                ret = add(ret, cur[L][i]);
            }
        } else {
            int a = lz[L][0], b = lz[L][1];
            lz[L][0] = lz[L][1] = 0;
            if(a + b) {
                for(int i = 2; i < (int) cur[L].size(); i++) {
                    cur[L][i] = add(cur[L][i], add(a, b));
                    swap(a, b);
                    b = add(a, b);
                }
            }
            for(int i = lb; i < (int) cur[L].size(); i++) {
                ret = add(ret, cur[L][i]);
            }

            for(int i = L + 1; i < R; i++) {
                ret = add(ret, sm[i]);
            }

            a = lz[R][0], b = lz[R][1];
            lz[R][0] = lz[R][1] = 0;
            if(a + b) {
                for(int i = 2; i < (int) cur[R].size(); i++) {
                    cur[R][i] = add(cur[R][i], add(a, b));
                    swap(a, b);
                    b = add(a, b);
                }
            }
            for(int i = 0; i <= rb; i++) {
                ret = add(ret, cur[R][i]);
            }
        }

        return ret;
    };

    while(q--) {
        int ty, l, r; cin>>ty>>l>>r;
        --l; --r;
        if(ty == 1) {
            upd(l, r);
        } else {
            cout<<qur(l, r)<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fib[0] = fib[1] = 1;
    for(int i = 2; i < N; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }

    pf[0] = 1;
    for(int i = 1; i < N; i++) {
        pf[i] = (pf[i - 1] + fib[i]) % mod;
    }

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