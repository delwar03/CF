#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 998244353;
const int N = 1e3 + 10;
const int K = 30;
const int MX_NUM = 60 * N;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

int fib[K];
int dp[N][MX_NUM], bit_cnt[MX_NUM];

int add(int a, int b) {
    a += b;
    return (a >= mod ? a - mod : a);
}

int getBits(int n) {
    int cnt = 0, tmp = n;
    string num = "";
    for(int i = K - 1; i >= 0; i--) {
        if(tmp - fib[i] >= 0) {
            tmp -= fib[i];
            cnt++;
            num += "1";
        } else {
            num += "1";
        }
    }
    // cerr<<num<<" ";
    return cnt;
}

void solve() {
    int n, x, m; cin>>n>>x>>m;

    dp[0][0] = 1;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < n; j++) {
            for(int sm = 0; sm <= j * fib[i]; sm++) {
                dp[j + 1][sm + fib[i]] = add(dp[j + 1][sm + fib[i]], dp[j][sm]);
            }
        }
    }

    int ans = 0;
    for(int sm = 0; sm < MX_NUM; sm++) {
        if(bit_cnt[sm] == m) {
            ans = add(ans, dp[n][sm]);
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fib[0] = fib[1] = 1;

    for(int i = 2; i < K; i++) fib[i] = add(fib[i - 1], fib[i - 2]);

    for(int i = 0; i < MX_NUM; i++) bit_cnt[i] = getBits(i);

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
