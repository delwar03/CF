#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    cout<<(*max_element(v.begin(), v.begin() + n - 1) + v[n - 1])<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/