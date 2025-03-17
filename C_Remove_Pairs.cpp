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

int dp[20][1LL << 18][2];

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i]>>b[i];

    int res = 0;

    function<int(int, int, int)> magic = [&] (int ind, int mask, int f) {
        if(ind == n) {
            res |= f;
            return f;
        }
        int &ans = dp[ind][mask][f];
        if(~ans) return ans;

        ans = 0;

        for(int j = ind + 1; j < n; j++) {
            if(mask & (1LL << j)) continue;
            if(a[ind] == a[j] || b[ind] == b[j]) {
                ans |= magic(ind + 1, mask | (1LL << j), f ^ 1);
            }
        }
        return ans;
    };

    memset(dp, -1, sizeof dp);
    magic(0, 0, 1);
    cout<<(res ? "Takahashi" : "Aoki")<<endl;
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