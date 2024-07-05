#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m, x; cin>>n>>m>>x;

    auto f = [&] (int a, int b) {
        if(a <= 0 || b <= 0) return 0LL;
        return (a * b + 1) / 2;
    };

    int a = n - 2 * (x - 1), b = m - 2 * (x - 1);
    int c = n - 2 * x, d = m - 2 * x;

    cout<<f(a, b) - f(c, d)<<endl;
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