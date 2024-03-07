#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    int grid[n + 1][n + 1];
    memset(grid, -1, sizeof grid);
    for(int i = 1; i <= n; i++) {
        cin>>grid[i][i];
    }
    
    for(int i = 1; i <= n; i++) {
        int p = grid[i][i], val = p;
        int x = i, y = i;
        while(p--) {
            grid[x][y] = val;
            if(y > 1 && grid[x][y - 1] == -1) y--;
            else x++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<grid[i][j]<<" \n"[j == i];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 