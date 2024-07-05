#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<int> pf(n + 1);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] + (s[i] - '0');
    }

    map<int, int> mp;
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += mp[pf[i] - i];
        mp[pf[i] - i]++;
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