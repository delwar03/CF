#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<string> col(n);
    for(auto &x : col) cin>>x;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int id = 0;

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            int r = i;
            dp[i][j] = ++id;
            while(r + 1 < n && col[r][j] == col[r + 1][j]) {
                r++;
                dp[r][j] = id;
            }
            i = r;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 2; j < n; j += 3) {
            int len = (j - i + 1);
            int left = i, mid = left + len / 3, right = mid + len / 3;
            for(int k = 0; k < m; k++) {
                int ll = k, rr = k;
                if(dp[left][k] == dp[mid - 1][k] && dp[mid - 1][k] != dp[mid][k] && dp[mid][k] == dp[right - 1][k] && dp[right - 1][k] != dp[right][k] && dp[right][k] == dp[j][k]) {
                    while((rr + 1 < m && dp[left][rr + 1] == dp[mid - 1][rr + 1] && dp[mid - 1][rr + 1] != dp[mid][rr + 1] && dp[mid][rr + 1] == dp[right - 1][rr + 1] && dp[right - 1][rr + 1] != dp[right][rr + 1] && dp[right][rr + 1] == dp[j][rr + 1]) && (col[left][rr] == col[left][rr + 1] && col[mid][rr] == col[mid][rr + 1] && col[right][rr] == col[right][rr + 1])) {
                        rr++;
                    }
                    int cur = rr - ll + 1;
                    ans += cur * (cur + 1) / 2;
                    k = rr;
                }
            }
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