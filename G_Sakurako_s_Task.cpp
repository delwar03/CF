#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    int g = 0;
    for(auto &x : v) {
        cin>>x;
        g = __gcd(g, x);
    }

    int ans = 0;
    
    if(n == 1) {
        ans = (k - 1) + (k - 1 >= g);
    } else {
        ans = k;
        for(int i = 1; i < n; i++) {
            if(ans >= i * g) ans++;
        }
    }
    cout<<ans<<endl;
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