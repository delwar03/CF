#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<string> v(n);
    for(auto &x : v) {
        cin>>x;
    }
    int ans = 0;
    for(int j = 0; j < n; j++) {
        for(int i = n - 1; i >= 0; i--) {
            if(v[j][n - 1 - i] <= v[i][j]) {
                ans += v[i][j] - v[j][n - 1 - i]; 
                v[j][n - 1 - i] = v[i][j];
            } else {
                ans += v[j][n - 1 - i] - v[i][j]; 
                v[i][j] = v[j][n - 1 - i];
            }
        }
    }
    for(int j = 0; j < n; j++) {
        for(int i = n - 1; i >= 0; i--) {
            if(v[j][n - 1 - i] <= v[i][j]) {
                ans += v[i][j] - v[j][n - 1 - i]; 
                v[j][n - 1 - i] = v[i][j];
            } else {
                ans += v[j][n - 1 - i] - v[i][j]; 
                v[i][j] = v[j][n - 1 - i];
            }
        }
    }
    // for(auto x : v) cout<<x<<endl;
    // cout<<endl;
    cout<<ans<<endl;
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