#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define f first
#define s second
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

pair<int, int> ov[55]; // original
pair<int, int> cv[55]; // current
int f[N], g[N];
int dp[55][N];

void solve() {
    int n, m; cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>ov[i].f>>ov[i].s;

    auto compute = [&] (int m) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;

        for(int i = 0; i < n; i++) {
            int tot = 0;
            int l = cv[i].f, r = cv[i].s;
            for(int j = 0; j <= m; j++) {
                if(j >= l) tot = (tot + dp[i][j - l]) % mod;
                dp[i + 1][j] = tot;
                if(j >= r) tot = (tot - dp[i][j - r] + mod) % mod;
            }
        }

        int sm = 0;
        for(int i = 0; i <= m; i++) sm = (sm + dp[n][i]) % mod;
        return sm;
    };

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            cv[j].f = (ov[j].f + i - 1) / i; 
            cv[j].s = (ov[j].s) / i;
        }
        g[i] = compute(m / i);
    }

    for(int i = m; i > 0; i--) {
        f[i] = g[i];
        for(int j = 2 * i; j <= m; j += i) {
            f[i] = (f[i] - f[j] + mod) % mod;
        }
    }
    cout<<f[1]<<endl;
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