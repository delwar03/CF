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
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[105][2];

int tt = 10;

int f(int n, int t) {
    if(n == 0) return 0;
    int &ans = dp[n][t];
    if(~ans) return ans;
    ans = 0;
    set<int> st;
    if(t == 0) {
        for(int i = 2; 2 * i <= tt && n - i >= 0; i += 2) {
            st.insert(f(n - i, !t));
        }
    } else {
        for(int i = 1; 2 * i <= tt && n - i >= 0; i += 2) {
            st.insert(f(n - i, !t));
        }
    }
    while(st.count(ans)) ans++;
    return ans;
}

void solve() {
    int n, p; cin>>n>>p;
    if(n == 1) {
        cout<<(p == 1 ? "Evenius" : "Oddius")<<endl;
        return;
    }
    if(p == 1) { //odd
        cout<<"Oddius"<<endl;
    } else {
        int f = (n % 4 == 1);
        cout<<(f ? "Evenius" : "Oddius")<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // memset(dp, -1, sizeof dp);

    // for(int i = 1; i <= 100; i++) {
    //     for(int j : {0, 1}) {
    //         tt = i;
    //         dp[i][j] = f(i, j);
    //     }
    // }

    // for(int i = 1; i <= 100; i++) cerr<<i<<" -> "<<dp[i][0]<<"\n"; cerr<<endl;
    // for(int i = 1; i <= 100; i++) cerr<<i<<" -> "<<dp[i][1]<<"\n"; cerr<<endl;

    // tt = 5;

    // cerr<<tt<<" -> "<<f(tt, 0)<<endl;
    // cerr<<tt<<" -> "<<f(tt, 1)<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}