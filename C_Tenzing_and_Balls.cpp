       

        //  ▄████▄   ▒█████  ▓█████▄ ▓█████ 
        // ▒██▀ ▀█  ▒██▒  ██▒▒██▀ ██▌▓█   ▀ 
        // ▒▓█    ▄ ▒██░  ██▒░██   █▌▒███   
        // ▒▓▓▄ ▄██▒▒██   ██░░▓█▄   ▌▒▓█  ▄ 
        // ▒ ▓███▀ ░░ ████▓▒░░▒████▓ ░▒████▒
        // ░ ░▒ ▒  ░░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░
        //   ░  ▒     ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░
        // ░        ░ ░ ░ ▒   ░ ░  ░    ░   
        // ░ ░          ░ ░     ░       ░  ░
        // ░                  ░             
 

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1), lst(n + 1, -1), dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
    }
    lst[v[1]] = 1;
    for(int i = 2; i <= n; i++) {
        int x = v[i];
        if(lst[x] == -1) dp[i] = dp[i - 1];
        else {
            dp[i] = max(dp[i - 1], dp[lst[x]] + (i - lst[x]));
            if(lst[x] != 1) dp[i] = max(dp[i], dp[lst[x] - 1] + (i - lst[x] + 1));
            else dp[i] = i;
        }
        lst[x] = i;
    }
    for(int i = 1; i <= n; i++) cerr<<dp[i]<<" "; cerr<<endl;
    cout<<dp[n]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 