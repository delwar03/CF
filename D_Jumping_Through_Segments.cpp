#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> vec;

bool hobe(int m) {
    int u = 0, v = 0;
    for(auto it : vec) {
        u = max(it[0], u - m);
        v = min(it[1], v + m);
        if(u > v) return false;
    }
    return true;
}

void solve() {
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        vec.push_back({x, y});
    }
    int l = 0, r = INF, ans = 0; 
    while(l <= r) {
        int m = (l + r) / 2;
        if(hobe(m)) ans = m, r = m - 1;
        else l = m + 1;
    }
    cout<<ans<<endl;
    vec.clear();
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