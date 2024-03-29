#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        mp[x - i]++;
    }
    int ans = 0;
    for(auto it : mp) {
        int cnt = it.second;
        ans += cnt * (cnt - 1) / 2;
    }
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