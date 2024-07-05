#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    string s; cin>>s;
    s = "#" + s;
    int n = s.size();
    int ans = 0, f = 0;

    for(int i = 1; i < n; i++) {
        if(s[i - 1] != s[i]) ans++;
        if(s[i - 1] == '0' && s[i] == '1') f = 1;
    }

    cout<<ans - f<<endl;
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