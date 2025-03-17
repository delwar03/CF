#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int g[105][105];

int magic(int i, int j) {
    if(~g[i][j]) return g[i][j];
    set<int> cur;
    for(int u = 1; u <= max(i, j); u++) {
        if(i - u >= 0 && j - u >= 0) {
            cur.insert(magic(i - u, j));
            cur.insert(magic(i, j - u));
            cur.insert(magic(i - u, j - u));
        } else if(i - u >= 0) {
            cur.insert(magic(i - u, j));
        } else if(j - u >= 0) {
            cur.insert(magic(i, j - u));
        }
    }

    int mex = 0;
    while(cur.count(mex)) mex++;
    return g[i][j] = mex;
}

void solve() {
    int n; cin>>n;
    int xr = 0, f = 0;
    for(int i = 0; i < n; i++) {
        int a, b; cin>>a>>b;
        if(f || g[a][b] == INF) {f = 1; continue;}
        xr ^= g[a][b];
    }
    cout<<(f || xr ? "Y" : "N")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(g, -1, sizeof g);

    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            if(i == j || i == 0 || j == 0)
                g[i][j] = INF;
            else
                g[i][j] = magic(i, j);
        }
    }

    // for(int i = 0; i <= 100; i++) {
    //     for(int j = 0; j <= 100; j++) {
    //         cerr<<g[i][j]<<" \n"[j == 100];
    //     }
    // }

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