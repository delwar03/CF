#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[65][N];

void solve() {
    int n, k; cin>>n>>k;
    vector<int> pos(n + 1), v(n + 1);
    for(int i = 1; i <= n; i++) cin>>pos[i];
    for(int i = 1; i <= n; i++) cin>>v[i];

    for(int i = 0; i <= 63; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? pos[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    for(int i = 1; i <= n; i++) {
        int idx = i;
        for(int j = 63; j >= 0; j--) {
            if((k >> j) & 1) {
                idx = dp[j][idx];
            }
        }
        cout<<v[idx]<<" ";
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