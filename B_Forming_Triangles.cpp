#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n; cin>>n;
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        freq[x]++;
    }
    int ans = 0, cnt = 0;
    auto it = freq.begin();
    for(; it != freq.end(); it++) {
        int x = it->second;
        ++it;
        int y = 0;
        if(it != freq.end()) y = it->second;
        --it;
        cnt += x;
        ans += x * (x - 1) * (x - 2) / 6;
        ans += cnt * y * (y - 1) / 2;
        
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