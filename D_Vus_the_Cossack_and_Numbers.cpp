#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<double> v(n), ans;
    int sum = 0;
    for(auto &x : v) {
        cin>>x;
        ans.push_back(floor(x));
        sum += ans.back();
    }

    for(int i = 0; i < n && sum < 0; i++) {
        if(floor(v[i]) != v[i]) {
            ans[i]++;
            sum++;
        }
    }

    for(auto it : ans) cout<<it<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/