#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> pos(n + 1), v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        pos[v[i]] = i;
    }
    int dp[n + 1];
    memset(dp, -1, sizeof dp);
    dp[1] = 1; dp[n] = 0;

    for(int i = n - 1; i > 1; i--) {
        bool win = false;
        for(int j = pos[i] + i; j <= n; j += i) {
            if(v[j] > i && dp[v[j]] == 0) {
                win = true;
                break;
            }
        }
        for(int j = pos[i] - i; j >= 1; j -= i) {
            if(v[j] > i && dp[v[j]] == 0) {
                win = true;
                break;
            }
        }
        dp[i] = win;
    }

    // for(int i = 1; i <= n; i++) {
    //     cout<<dp[v[i]]<<" ";
    // } cout<<endl;

    for(int i = 1; i <= n; i++) {
        cout<<(dp[v[i]] == 1 ? "A" : "B");
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/