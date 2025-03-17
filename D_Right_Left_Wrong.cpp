#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    string s; cin>>s;
    vector<int> pf(n + 1), dp(n + 1);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] + v[i];
    }

    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') pq.push(i);
    }

    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            if(l == -1) l = i + 1;
        } else {
            r = i + 1;
        }
    }
    // cerr<<l<<" "<<r<<endl;

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if(s[i - 1] == 'L') {
            if(pq.empty()) break;
            r = pq.top();
            l = i;
            if(r < l) continue;
            // cerr<<"l: "<<l<<", r: "<<r<<endl;
            pq.pop();
            int sum = pf[r + 1] - pf[l - 1];
            // cerr<<"sum: "<<sum<<endl;
            dp[i] = dp[i - 1] + sum;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
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