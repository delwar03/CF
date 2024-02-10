#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

// Basic Floyd-Warshall Stuffs

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(1) {
        
        int n = 105;
        int dist[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        int u, v, ipCnt = 0;
        while(1) {
            cin>>u>>v;
            if(u == 0 && v == 0) break;
            dist[u][v] = 1;
            ipCnt++;
        }
        if(ipCnt == 0) break;
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] && dist[i][j] != INF) {
                    sum += dist[i][j];
                    cnt++;
                }
            }
        }
        cout<<"Case "<<c++<<": "<<"average length between pages = ";
        cout<<fixed<<setprecision(3)<< 1.0 * sum / cnt;
        cout<<" clicks\n";
    }
}
 
/*
i/p: 
o/p: 
*/ 