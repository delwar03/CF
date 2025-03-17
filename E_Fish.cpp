#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

double dp[1LL << 19];

void solve() {
    int n; cin>>n;
    vector<vector<double>> p(n, vector<double>(n));
    for(auto &x : p) for(auto &y : x) cin>>y;

    auto getProbab = [&] (int mask, int i) {
        int k = __builtin_popcount(mask);
        double d = k * (k - 1) / 2; 
        double sum = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(mask & (1LL << j)) {
                sum += p[j][i];
            }
        }
        return sum / d;
    };

    function<double(int)> magic = [&] (int mask) {

        int k = __builtin_popcount(mask);
        if(k == n) return 1.0;

        double &ans = dp[mask];
        if(ans >= 0.0) return ans;

        ans = 0.0;

        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) continue;
            int curMask = mask | (1LL << i);
            double prev = magic(curMask);
            ans += prev * getProbab(curMask, i);
        }

        return ans;
    };

    for(int mask = 0; mask < (1LL << 19); mask++) {
        dp[mask] = -1.0;
    }

    cout<<fixed<<setprecision(10);
    for(int i = 0; i < n; i++) {
        int curMask = (1LL << i);
        cout<<magic(curMask)<<" ";
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