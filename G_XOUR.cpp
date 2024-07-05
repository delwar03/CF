#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, priority_queue<int>> mp;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        mp[v[i] >> 2].push(-v[i]);
    }

    for(auto x : v) {
        cout<<-mp[x >> 2].top()<<" ";
        mp[x >> 2].pop();
    }
    cout<<endl;
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