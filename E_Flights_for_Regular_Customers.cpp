#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
#define Mat array<bitset<N>, N>
using namespace std;
const int mod = 1e9 + 7;
const int N = 160;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

Mat adj, dp;
int dist[N][N], tmp[N][N];

void solve() {
    int n, m; cin>>n>>m;
    vector<array<int, 3>> edges(m);
    for(auto &[d, u, v] : edges) cin>>u>>v>>d;
    sort(edges.begin(), edges.end());

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            tmp[i][j] = (i == j ? 0 : INF);
        }
    }

    auto mul = [&] (Mat a, Mat b) {
        Mat res, trans;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(b[i].test(j)) {
                    trans[j].set(i);
                }
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if((a[i] & trans[j]).any()) {
                    res[i].set(j);
                }
            }
        }
        return res;
    };

    auto matPow = [&] (Mat a, int b) {
        Mat res;
        for(int i = 0; i <= n; i++) res[i].set(i);
        while(b > 0) {
            if(b & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    };

    int ans = INF, prv = 0;
    dp[1].set(1);
    
    for(auto &[d, u, v] : edges) {
        dp = mul(dp, matPow(adj, d - prv));
        prv = d;
        adj[u].set(v);
        tmp[u][v] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = tmp[i][j];
            }
        }

        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(dp[1].test(i)) {
                ans = min(ans, d + dist[i][n]);
            }
        }
    }

    if(ans == INF) {
        cout<<"Impossible"<<endl;
    } else {
        cout<<ans<<endl;
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