#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 105;
const int INF = 1e15 + 10;

int dp[N][N];

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    string t; cin>>t;
    int tl = t.size();
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        // not chosen any string from current bag
        for(int j = 0; j < 105; j++) dp[i + 1][j] = dp[i][j];

        int m; cin>>m;
        while(m--) {
            string s; cin>>s;
            int sl = s.size();
            for(int j = 0; j <= tl - sl; j++) {
                bool hobe = true;
                for(int k = 0; k < sl; k++) {
                    if(t[j + k] != s[k]) {
                        hobe = false;
                        break;
                    }
                }

                if(hobe) {
                    dp[i + 1][j + sl] = min(dp[i + 1][j + sl], dp[i][j] + 1);
                }
            }
        }
    }
    cout<<(dp[n][tl] == INF ? -1 : dp[n][tl])<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 