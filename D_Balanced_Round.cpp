#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());
    int cnt = 1, mx = 0;
    for(int i = 1; i < n; i++) {
        if(v[i] - v[i - 1] <= k) {
            cnt++;
        } else {
            mx = cnt > mx ? cnt : mx;
            cnt = 1;
        }
    }
    mx = cnt > mx ? cnt : mx;
    // cerr<<"mx: "<<mx<<endl;
    cout<<n - mx<<endl;
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