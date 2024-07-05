#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i = 1; i <= n; i++) {
        int x, y; cin>>x>>y;
        v.push_back({y, x, i});
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++) {
        if(v[i][1] <= 10) {
            cout<<v[i][2]<<endl;
            return;
        }
    }
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