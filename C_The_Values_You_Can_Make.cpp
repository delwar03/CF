#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int dp[2][505][505]; // i projonto, subset sum j, k

void solve() {
    int n, w; cin>>n>>w;
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++) cin>>val[i];

    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        int cur = i % 2;
        int prv = !cur;
        for(int j = 0; j <= w; j++) {
            for(int k = 0; k <= w; k++) {
                dp[cur][j][k] = dp[prv][j][k];
                if(j - val[i] >= 0) {
                    dp[cur][j][k] |= dp[prv][j - val[i]][k];
                    if(k - val[i] >= 0) {
                        dp[cur][j][k] |= dp[prv][j - val[i]][k - val[i]];
                    }
                }
            }
        }
    }

    vector<int> ans;

    for(int j = 0; j <= w; j++) {
        if(dp[n % 2][w][j]) {
            ans.push_back(j);
        }
    }
    
    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it<<" ";
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