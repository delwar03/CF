#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// dp[{ind, g1, g2, type}]

map<pair<int, int>, int> dp[N][3];
map<pair<int, int>, int> ndp[N][3];

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j].clear();
            ndp[i][j].clear();
        }
    }

    function<int(int, int, int, int)> magic = [&] (int ind, int g1, int g2, int f) {
        if(ind == n) return (f == 2 ? g1 + g2 : 0);
        if(dp[ind][f].count({g1, g2})) return dp[ind][f][{g1, g2}];
        int &ans = dp[ind][f][{g1, g2}];
        ans = 0;

        if(f == 0) {
            ans = max(ans, magic(ind + 1, __gcd(g1, a[ind]), __gcd(g2, b[ind]), 0));
            ans = max(ans, magic(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 1));
            ans = max(ans, magic(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 2));
        } else if(f == 1) {
            ans = max(ans, magic(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 1));
            ans = max(ans, magic(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 2));
        } else {
            ans = max(ans, magic(ind + 1, __gcd(g1, a[ind]), __gcd(g2, b[ind]), 2));
        }

        return ans;
    };

    function<int(int, int, int, int, int)> getCnt = [&] (int ind, int g1, int g2, int f, int cur) {
        if(ind == n) return (int) (f == 2 && (g1 + g2 == cur));
        if(ndp[ind][f].count({g1, g2})) return ndp[ind][f][{g1, g2}];
        int &ans = ndp[ind][f][{g1, g2}];
        ans = 0;

        if(f == 0) {
            ans += getCnt(ind + 1, __gcd(g1, a[ind]), __gcd(g2, b[ind]), 0, cur);
            ans += getCnt(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 1, cur);
            ans += getCnt(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 2, cur);
        } else if(f == 1) {
            ans += getCnt(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 1, cur);
            ans += getCnt(ind + 1, __gcd(g1, b[ind]), __gcd(g2, a[ind]), 2, cur);
        } else {
            ans += getCnt(ind + 1, __gcd(g1, a[ind]), __gcd(g2, b[ind]), 2, cur);
        }

        return ans;
    };


    int mxAns = magic(0, 0, 0, 0);
    int ways = getCnt(0, 0, 0, 0, mxAns);

    cout<<mxAns<<" "<<ways<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/