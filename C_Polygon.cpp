#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<string> v(n);
    for(auto &s : v) cin>>s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '1') {
                if(i == n - 1 || j == n - 1 || v[i][j + 1] == '1' || v[i + 1][j] == '1') continue;
                else {cout<<"NO\n"; return;}
            }
        }
    }
    cout<<"YES\n";
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