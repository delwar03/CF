#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, w; cin>>n>>w;
    int mn = 0, mx = 0, sum = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        sum += x;
        mn = sum < mn ? sum : mn;
        mx = sum > mx ? sum : mx;
    }

    int min_x = 0 - mn;
    int max_x = w - mx;

    cout<<max(0LL, max_x - min_x + 1)<<endl;
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