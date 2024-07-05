#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, a, b; cin>>n>>a>>b;

    auto f = [&] (int k) {
        return a * (n - k) + (b + 1) * k - k * (k + 1) / 2;
    };

    int l = 0, r = min(n, b);
    int ans = n * a;
    while(l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if(f(m1) < f(m2)) {
            l = m1 + 1;
        } else if(f(m2) < f(m1)) {
            r = m2 - 1;
        } else {
            ans = f(m1);
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    cout<<ans<<endl;
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