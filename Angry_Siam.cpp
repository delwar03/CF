#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 2150;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int should[60][60];
int a[N], v[N], ang[N], freq[N];
int OP[N], X[N], Y[N], ans[N];
int n, q, cur = 0;

void solve() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &ang[i]);
        ang[i] += ang[i - 1];
    }
    
    scanf("%lld", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%lld %lld %lld", &OP[i], &X[i], &Y[i]);
        should[X[i] / BLK][Y[i] / BLK] = 1;
    }

    auto upd = [&] (int x, int val) {
        cur -= ang[freq[x]] * x;
        freq[x] += val;
        cur += ang[freq[x]] * x;
    };

    auto f = [&] (int lb, int rb) {
        fill(freq, freq + N, 0LL);
        for(int i = 1; i <= n; i++) a[i] = v[i];

        int l = 1, r = 1;
        cur = ang[1] * a[1];
        freq[a[1]]++;

        for(int i = 1; i <= q; i++) {
            int x = X[i], y = Y[i], op = OP[i];
            if(op == 2) {
                cur -= ang[freq[a[x]]] * a[x];
                if(l <= x && x <= r) freq[a[x]]--;
                cur += ang[freq[a[x]]] * a[x];

                a[x] = y;

                cur -= ang[freq[a[x]]] * a[x];
                if(l <= x && x <= r) freq[a[x]]++; 
                cur += ang[freq[a[x]]] * a[x];
            } else if(x / BLK == lb && y / BLK == rb) {
                while(r < y) upd(a[++r], +1);
                while(l > x) upd(a[--l], +1);

                while(r > y) upd(a[r--], -1);
                while(l < x) upd(a[l++], -1);

                ans[i] = cur;
            }
        }
    };

    for(int i = 0; i < 60; i++) {
        for(int j = 0; j < 60; j++) {
            if(should[i][j]) {
                f(i, j);
            }
        }
    }

    for(int i = 1; i <= q; i++) {
        if(OP[i] == 1) printf("%lld\n", ans[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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