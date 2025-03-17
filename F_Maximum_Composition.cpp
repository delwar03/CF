#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[1LL << 17];

void solve() {
    int n, k; cin>>n>>k;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int a, b; cin>>a>>b;
        v.push_back({a, b});
    }

    sort(v.rbegin(), v.rend());

    int m = min(n, 17LL);

    function<int(int)> magic = [&] (int mask) {
        if(mask == 0) return 1LL;

        int &ans = dp[mask];
        if(~ans) return ans;

        ans = 0;

        for(int i = 0; i < m; i++) {
            if(mask & (1 << i)) {
                ans = max(ans, v[i][0] * magic(mask ^ (1LL << i)) + v[i][1]);
            }
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    int mask = (1LL << m);
    int ans = 0;
    for(int i = 1; i < mask; i++) {
        if(__builtin_popcount(i) == k) {
            ans = max(ans, magic(i));
        }
    }

    cout<<ans<<endl;
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