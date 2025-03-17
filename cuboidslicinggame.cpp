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

int g[35][35][35];

bool isValid(int a, int b, int c) {
    return a >= 0 && a <= 30 && b >= 0 && b <= 30 && c >= 0 && c <= 30;
}

int magic(int a, int b, int c) {
    if(!isValid(a, b, c)) return 999;
    if(~g[a][b][c]) return g[a][b][c];
    vector<int> vis(1000);

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            for(int k = 0; k < c; k++) {
                vis[magic(i, j, k) ^ magic(i, j, c - 1 - k) ^
                    magic(i, b - 1 - j, k) ^ magic(a - 1 - i, j, k) ^ 
                    magic(a - 1 - i, b - 1 - j, k) ^ magic(a - 1 - i, j, c - 1 - k) ^
                    magic(i, b - 1 - j, c - 1 - k) ^ magic(a - 1 - i, b - 1 - j, c - 1 - k)] = 1;
            }
        }
    }
    int mex = 0;
    while(vis[mex]) mex++;

    return g[a][b][c] = mex;
}

void solve() {
    string s1, s2; cin>>s1;
    s2 = (s1 == "RUBEN" ? "ALBERT" : "RUBEN");
    int n; cin>>n;
    int xr = 0;
    for(int i = 0; i < n; i++) {
        int a, b, c; cin>>a>>b>>c;
        xr ^= magic(a, b, c);
    }
    cout<<(xr ? s1 : s2)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(g, -1, sizeof g);

    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
            for(int k = 0; k <= 20; k++) {
                if(i * j * k == 0)
                    g[i][j][k] = 0;
            }
        }
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