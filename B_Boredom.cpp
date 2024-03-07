#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    vector<int> freq(N, 0), dp(N, 0);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        freq[x]++;
    }

    dp[1] = freq[1];
    for(int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
    }
    cout<<dp[N - 1]<<endl;
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