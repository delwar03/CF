#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<string> v(n);
    int mx = 0;
    for(auto &x : v) cin>>x, mx = max(mx, (int) x.size());
    reverse(v.begin(), v.end());

    vector<string> ans(mx);

    for(int i = 0; i < n; i++) {
        string cur;
        for(int j = 0; j < mx; j++) {
            if(j < (int) v[i].size())
                ans[j] += v[i][j];
            else
                ans[j] += "*";
        }
        // cerr<<cur<<" ";
    }

    for(auto &x : ans) {
        while(x.back() == '*') x.pop_back();
    }

    for(auto it : ans) cout<<it<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/