#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> row(n, 0), col(n, 0);

    int freeCells = n * n, filledRow = 0, filledCol = 0;

    for(int i = 0; i < m; i++) {
        int x, y; cin>>x>>y;
        x--; y--;
        int sub = 2 * n - 1;
        if((!row[x]) && (!col[y])) {
            sub -= (filledRow + filledCol);
        } else {
            if(row[x]) {
                sub -= n;
                sub -= filledRow - 1;
            }
            if(col[y]) {
                sub -= n;
                sub -= filledCol - 1;
            }
        }

        if(!row[x]) {row[x] = 1; filledRow++; }
        if(!col[y]) {col[y] = 1; filledCol++; }

        if(sub < 0) sub = 0;
        freeCells -= sub;
        // cerr<<sub<<endl;
        cout<<max(0LL, freeCells)<<" \n"[i == n - 1];
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
