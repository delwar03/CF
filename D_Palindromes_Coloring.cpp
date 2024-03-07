#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    map<char, int> mp;
    for(auto ch : s) mp[ch]++;
    // for(auto it : mp) cerr<<it.first<<" -> "<<it.second<<endl;
    int pair = 0, nonPair = 0;
    for(auto it : mp) {
        pair += it.second / 2;
        nonPair += it.second % 2;
    }
    int ans = pair / k;
    nonPair += (pair % k) * 2;
    bool f = nonPair >= k;
    cout<<ans * 2 + f<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": "<<endl;;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 