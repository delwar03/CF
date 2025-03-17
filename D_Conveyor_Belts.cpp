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
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int X[N][12], Y[N][12];

void solve() {
    int n, m, q; cin>>n>>m>>q;
    vector<string> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        v[i] = "#" + v[i];
    }

    for(int i = 0; i <= n + 1; i++) {
        X[i][0] = X[i][m + 1] = i;
        Y[i][0] = 0, Y[i][m + 1] = m + 1;
    }
    for(int j = 0; j <= m + 1; j++) {
        X[0][j] = 0, X[n + 1][j] = n + 1;
        Y[0][j] = Y[n + 1][j] = j;
    }

    auto isValid = [&] (int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    auto upd = [&] (int l, int r) {
        for(int i = l; i <= r; i++)
            for(int j = 1; j <= m; j++)
                X[i][j] = Y[i][j] = -1;

        for(int i = l; i <= r; i++) {
            for(int j = 1; j <= m; j++) {
                if(v[i][j] == '^') {
                    X[i][j] = (i == l ? i - 1 : X[i - 1][j]), Y[i][j] = (i == l ? j : Y[i - 1][j]);
                } else if(v[i][j] == '<') {
                    X[i][j] = X[i][j - 1], Y[i][j] = Y[i][j - 1];
                }
            }
            for(int j = m; j >= 1; j--) if(v[i][j] == '>') {
                X[i][j] = X[i][j + 1], Y[i][j] = Y[i][j + 1];
            }
        }
    };

    for(int i = 0; i <= n; i += BLK) {
        int l = max(1LL, (i / BLK) * BLK), r = min(n, l + BLK - 1);
        upd(l, r);
    }

    while(q--) {
        char ty; cin>>ty;
        if(ty == 'A') {
            int x, y; cin>>x>>y;
            while(isValid(x, y)) {
                int tmp = x;
                x = X[tmp][y];
                y = Y[tmp][y];
            }
            cout<<x<<" "<<y<<endl;
        } else {
            int x, y; char cur; cin>>x>>y>>cur;
            int l = max(1LL, (x / BLK) * BLK), r = min(n, l + BLK - 1);
            v[x][y] = cur;
            upd(l, r);
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