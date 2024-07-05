#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    int g = 0, mx = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        g = __gcd(g, x);
        mx = x > mx ? x : mx;
    }
    mx /= g;
    mx -= n;
    cout<<(mx & 1 ? "Alice" : "Bob")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/