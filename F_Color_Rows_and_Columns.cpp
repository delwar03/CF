#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int dp[1005][105], ndp[1005][105];

void solve() {
    int n, k; cin>>n>>k;
    vector<vector<int>> v;
    v.push_back({0, 0});
    for(int i = 1; i <= n; i++) {
        int a, b; cin>>a>>b;
        v.push_back({a, b}); // {w, h}
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = -1;
            ndp[i][j] = INF;
        }
    }

    ndp[0][0] = 0;

    for(int i = 0; i <= n; i++) {
        ndp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= v[i][0]; w++) {
            for(int h = 0; h <= v[i][1]; h++) {
                int scr = w + h;
                if(scr <= k) {
                    ndp[i][scr] = min(ndp[i][scr], w * v[i][1] + h * v[i][0] - h * w);
                }
            }
        }
    }

    function<int(int, int)> magic = [&] (int ind, int tot) {
        if(ind == n + 1) return (tot == 0 ? 0LL : INF);

        int &ans = dp[ind][tot];
        if(~ans) return ans;

        ans = INF;

        for(int i = 0; i <= tot; i++) {
            ans = min(ans, ndp[ind][i] + magic(ind + 1, tot - i));
        }

        return ans;
    };

    int ans = magic(0, k);
    cout<<(ans == INF ? -1 : ans)<<endl;
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