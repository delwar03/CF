#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[81][81][81][81]; // (len, cur, prv, l_prv)

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 0; i < n; i++) cin>>v[i];

    function<int(int, int, int, int)> magic = [&] (int len, int cur, int prv, int l_prv) {
        if(cur >= n) {
            return (int) (len == 0);
        }

        int &ans = dp[len][cur][prv][l_prv];
        if(~ans) return ans;

        ans = 0;
        ans += magic(len, cur + 1, prv, l_prv);
        ans %= mod;
        if(v[cur] - v[prv] == v[prv] - v[l_prv] && len - 1 >= 0) {
            ans += magic(len - 1, cur + 1, cur, prv);
            ans %= mod;
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    for(int k = 1; k <= n; k++) {
        if(k == 1) {
            cout<<n<<" ";
        } else if(k == 2) {
            cout<<n * (n - 1) / 2<<" ";
        } else {
            int ans = 0;
            for(int l_prv = 0; l_prv < n; l_prv++) {
                for(int prv = l_prv + 1; prv < n; prv++) {
                    ans += magic(k - 2, prv + 1, prv, l_prv);
                    ans %= mod;
                }
            }
            cout<<ans<<" ";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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