#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

map<int, int> dp;

int f(int n) {
    if(dp.count(n)) return dp[n];
    return dp[n] = n + f(n / 2) + f((n + 1) / 2);
}

void solve() {
    dp[1] = 0;
    dp[2] = 2;

    int n; cin>>n;
    int ans = f(n);
    cout<<ans<<endl;
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