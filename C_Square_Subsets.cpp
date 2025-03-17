#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 71;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int siv[N], f[N][2], msk[N], dp[N][1LL << 19];
vector<int> prime;

void solve() {
    int n; cin>>n;
    vector<int> v(n);

    for(auto &x : v) {
        cin>>x;
        f[x][1] = f[x][0] = (f[x][0] + f[x][1]) % mod;
    }

    int sz = sz(prime), mask = (1LL << sz);
    dp[0][0] = 1;

    for(int i = 1; i <= 70; i++) {
        for(int j = 0; j < mask; j++) {
            dp[i][j] = (1LL * dp[i - 1][j] * f[i][0]) % mod;
            (dp[i][j] += (1LL * dp[i - 1][j ^ msk[i]] * f[i][1]) % mod) %= mod;
        }
    }
    
    cout<<(dp[70][0] - 1 + mod) % mod<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(siv, siv + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(siv[i] == i) {
            prime.push_back(i);
            for(int j = i; j < N; j += i) {
                if(siv[j] == j) {
                    siv[j] = i;
                }
            }
        }
    }

    // for(auto it : prime) cerr<<it<<" "; cerr<<endl;

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < sz(prime); j++) {
            int tmp = i;
            while(tmp % prime[j] == 0) tmp /= prime[j], msk[i] ^= (1 << j);
        }
    }

    for(int i = 1; i < N; i++) f[i][0] = 1;

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}