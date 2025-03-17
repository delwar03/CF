#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n), pf(n + 1);
    for(auto &x : v) cin>>x;
    for(int i = 1; i <= n; i++) {
        pf[i] = pf[i - 1] + v[i - 1];
    }

    vector<int> maxCanEat(n + 1);
    maxCanEat[n] = n;
    for(int i = n - 1; i >= 0; i--) {
        if(pf[i] >= (pf[i + 1] - pf[i])) {
            maxCanEat[i] = maxCanEat[i + 1];
        } else {
            maxCanEat[i] = i;
        }
    }

    map<vector<int>, int> dp;

    function<int(int, int)> magic = [&] (int l, int r) {
        vector<int> cur = {l, r};
        if(dp.count(cur)) return dp[cur];

        if(l == 1) {
            return dp[cur] = r;
        }

        int curSum = pf[r] - pf[l - 1];

        // pf[l - 1] - pf[i - 1] <= curSum
        // pf[l - 1] - curSum <= pf[i - 1]

        int newL = lower_bound(pf.begin(), pf.end(), pf[l - 1] - curSum) - pf.begin() + 1;
        if(newL != l) {
            return dp[cur] = magic(newL, r);
        }

        // pf[j] - pf[l - 1] >= prv
        // pf[l - 1] + prv <= pf[j]

        int prv = pf[l - 1] - pf[l - 2];

        int newR1 = lower_bound(pf.begin(), pf.end(), pf[l - 1] + prv) - pf.begin();
        int newR2 = upper_bound(pf.begin(), pf.end(), pf[r] + curSum) - pf.begin() - 1;

        // cerr<<newR1<<" "<<newR2<<endl;

        if(newR1 <= newR2) {
            return dp[cur] = magic(l, newR1);
        } 
        if(newR2 != r) {
            return dp[cur] = magic(l, newR2);
        }
        
        return dp[cur] = -1;
    };

    vector<int> res(n + 2);

    for(int i = 1; i <= n; i++) {
        int minInd = magic(i, i);
        if(~minInd) {
            int maxInd = maxCanEat[minInd];
            res[minInd]++;
            res[maxInd + 1]--;
        }
    }

    for(int i = 1; i <= n; i++) {
        res[i] += res[i - 1];
    }

    for(int i = k; i <= n; i++) cout<<res[i]<<" \n"[i == n];

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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