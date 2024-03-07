#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, m;
vector<int> par, vis;
int table[31][N];

void reset() {
    memset(table, 0, sizeof table);
    par.assign(n + 1, 0);
    vis.assign(n + 1, 0);
}

void buildTable() {
    for(int i = 0; i <= n; i++) table[0][i] = par[i];

    for(int i = 1; i < 30; i++) {
        for(int j = 0; j <= n; j++) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int query(int x) {
    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        
    }
}

void solve() {
    cin>>n;
    reset();
    for(int i = 1; i <= n; i++) {
        cin>>par[i];
    }
    vis[0] = 1;
    buildTable();
    // for(int i = 0; i < 30; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout<<table[i][j]<<" \n"[j == n];
    //     }
    // }
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        cout<<query(x)<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 