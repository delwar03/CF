#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int ans = 0;
    vector<int> b, c;
    b.push_back(INF);
    c.push_back(INF);
    for(int i = 0; i < n; i++) {
        if(b.back() > c.back()) swap(b, c);
        if(v[i] <= b.back() || v[i] > c.back()) b.push_back(v[i]);
        else c.push_back(v[i]);
    }
    for(int i = 0; i < b.size() - 1; i++) {
        if(b[i] < b[i + 1]) ans++;
    }
    for(int i = 0; i < c.size() - 1; i++) {
        if(c[i] < c[i + 1]) ans++;
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