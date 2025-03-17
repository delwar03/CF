#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[2][505][505]; // (ind, sum_1, sum_2)

void solve() {
    int n; cin>>n;
    vector<array<int, 2>> v(n);
    int sm = 0;
    for(auto &[a, b] : v) {
        cin>>a>>b;
        sm += b;
    }
    if(sm % 3) {cout<<-1<<endl; return; }

    for(int i = 0; i <= 500; i++)
        for(int j = 0; j <= 500; j++)
            dp[0][i][j] = dp[1][i][j] = INF;
    
    dp[0][0][0] = 0;
    int now = 0;

    for(auto &[a, b] : v) {
        int nxt = !now;
        for(int i = 0; i <= 500; i++) for(int j = 0; j <= 500; j++) dp[nxt][i][j] = INF;
        for(int j = 0; j <= 500; j++) {
            for(int k = 0; k <= 500; k++) {
                if(j + b <= 500) dp[nxt][j + b][k] = min(dp[nxt][j + b][k], dp[now][j][k] + (a != 1));
                if(k + b <= 500) dp[nxt][j][k + b] = min(dp[nxt][j][k + b], dp[now][j][k] + (a != 2));
                dp[nxt][j][k] = min(dp[nxt][j][k], dp[now][j][k] + (a != 3));
            }
        }
        now = nxt;
    }

    int ans = dp[now][sm / 3][sm / 3];
    cout<<(ans == INF ? -1 : ans)<<endl;
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