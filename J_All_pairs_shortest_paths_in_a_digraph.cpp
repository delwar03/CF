#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    int adjMat[n][n];

    int dist[n + 1][n + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i ^ j) dist[i][j] = INF;
            else dist[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>dist[i][j];
        }
    }
    for(int k = 0; k <= n; k++) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 