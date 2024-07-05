#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;

int dp[5005][5005];

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<int> pref(n + 1);

    for(int i = 0; i < n; i++) {
        pref[i + 1] = a[i] * b[i];
    }

    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
    }

    // for(auto it : pref) cerr<<it<<" "; cerr<<endl;

    for(int k = 1; k < n; k++) {
        for(int i = 0; i < n - k; i++) {
            int j = i + k;
            if(k == 1) {
                dp[i][j] = a[j] * b[i] + a[i] * b[j];
            } else if(k == 2) {
                dp[i][j] = a[j] * b[i] + a[j - 1] * b[i + 1] + a[j - 2] * b[i + 2]; 
            } else {
                dp[i][j] = dp[i + 1][j - 1] + a[j] * b[i] + a[i] * b[j];
            }
        }
    }

    int ans = pref[n];

    for(int k = 1; k < n; k++) {
        for(int i = 0; i < n - k; i++) {
            int j = i + k;
            int val = pref[n] - (pref[j + 1] - pref[i]);
            val += dp[i][j];
            ans = max(ans, val);
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
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 