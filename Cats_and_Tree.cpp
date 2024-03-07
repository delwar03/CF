#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
int n;
vector<int> par, pos, vis;
int table[31][N];

void reset() {
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j <= n; j++) {
            table[i][j] = 0;
        }
    }
    par.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    vis.assign(n + 1, 0);
}

void buildTable() {
    for(int i = 1; i <= n; i++) table[0][i] = par[i];
    for(int i = 1; i < 30; i++) {
        for(int j = 1; j <= n; j++) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int query(int cur) {
    if(vis[cur]) return 0;
    int ind = 1;
    for(int i = 30; i >= 0; i--) {
        int p = table[i][cur];
        if(!vis[p]) {
            cur = p;
            ind += (1LL << i);
        }
    }
    vis[cur] = 1;
    return ind;
}

void solve() {
    cin>>n;
    reset();
    for(int i = 1; i <= n; i++) cin>>par[i];
    // for(int i = 1; i <= n; i++) cin>>pos[i];
    buildTable();
    for(int i = 1; i <= n; i++) {
        int cur; cin>>cur;
        cout<<query(cur)<<endl;
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