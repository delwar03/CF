#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, a, b, c; cin>>n>>a>>b>>c;
    int p = b - c;
    int ans = n / a;
    
    if(p < a) {
        int cnt = (n - b + p) / p;
        int rem = n - cnt * p;
        cnt += rem / a;
        if(n < p) cnt = 0;

        ans = max(ans, cnt);
    }

    cout<<ans<<endl;
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