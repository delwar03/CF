#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[31][N];
int prime[N];
vector<int> primes;

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    double ans = 0;
    vector<int> sz(n + 1), par(n + 1);

    function<int(int, int)> dfs1 = [&] (int u, int p) {
        sz[u] = 1;
        for(auto v : g[u]) {
            if((v ^ p) && !par[v]) {
                sz[u] += dfs1(v, u);
            }
        }
        return sz[u];
    };

    function<int(int, int, int)> dfs2 = [&] (int u, int p, int cur) {
        for(auto v : g[u]) {
            if((v ^ p) && !par[v]) {
                if(2 * sz[v] > cur) {
                    return dfs2(v, u, cur);
                }
            }
        }
        return u;
    };

    function<void(int, int, int, int, int)> dfs3 = [&] (int u, int p, int dep, int dist, int delta) {
        dp[dep][dist] += delta;
        for(auto v : g[u]) {
            if((v ^ p) && !par[v]) {
                dfs3(v, u, dep, dist + 1, delta);
            }
        }
    };

    function<int(int, int, int, int)> dfs4 = [&] (int u, int p, int dep, int dist) {
        int ret = 0;
        for(auto prm : primes) {
            if(prm - dist >= 0) {
                if(!dp[dep][prm - dist]) break;
                if(prm == dist) {
                    ret += 2;
                } else {
                    ret += dp[dep][prm - dist];
                }
            }
        }

        for(auto v : g[u]) {
            if((v ^ p) && !par[v]) {
                ret += dfs4(v, u, dep, dist + 1);
            }
        }
        return ret;
    };

    function<void(int, int, int)> magic = [&] (int u, int p, int dep) {
        int cent = dfs2(u, p, dfs1(u, p));
        par[cent] = p;
        dfs3(cent, p, dep, 0, +1);
        int add = 0;
        for(auto v : g[cent]) {
            if(!par[v]) {
                dfs3(v, cent, dep, 1, -1);
                add += dfs4(v, cent, dep, +1);
                dfs3(v, cent, dep, 1, +1);
            }
        }
        ans += add / 2;
        for(auto v : g[cent]) {
            if(!par[v]) {
                magic(v, cent, dep + 1);
            }
        }
        for(int i = 0; i <= n && dp[dep][i]; i++) {
            dp[dep][i] = 0;
        }
    };

    magic(1, -1, 0);
    
    ans /= n * (n - 1) / 2.0;

    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) prime[i] = i;

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            primes.push_back(i);
            for(int j = i * 2; j < N; j += i) {
                if(prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }

    // for(int i = 0; i < 100; i++) cerr<<primes[i]<<" ";

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