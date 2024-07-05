#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    int n, m; cin>>n>>m;
    string s; cin>>s;
    map<char, int> mp;
    for(auto ch : s) {
        mp[ch]++;
    }
    int ans = 0;
    for(char ch = 'A'; ch <= 'G'; ch++) {
        if(mp[ch] < m) ans += (m - mp[ch]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/