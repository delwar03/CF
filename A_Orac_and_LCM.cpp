#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto LCM = [&] (int a, int b) {
        return (a * b) / __gcd(a, b);
    };

    vector<int> suff(n + 1);
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = __gcd(suff[i + 1], v[i]);
    }
    // for(auto it : suff) cerr<<it<<" "; cerr<<endl;


    vector<int> g(n);

    for(int i = 0; i < n; i++) {
        g[i] = LCM(v[i], suff[i + 1]);
    }

    // for(auto it : g) cerr<<it<<" "; cerr<<endl;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = __gcd(ans, g[i]);
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