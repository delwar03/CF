#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    priority_queue<vector<int>> pq;
    for(int i = 0; i < n; i++) {
        pq.push({a[i] + b[i] - 1, a[i], b[i]});
    }
    int id = 1, ans = 0;
    while(!pq.empty()) {
        if(id & 1) ans += pq.top()[1] - 1;
        else ans -= pq.top()[2] - 1;
        pq.pop();
        id++;
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