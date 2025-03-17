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

int inv(int n) {
    if(n <= 1) return n;
    return mod - (mod / n) * inv(mod % n) % mod;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sm = 0, ans = 0;
    for(auto &x : v) {
        cin>>x;
        ans = (ans + (sm * x) % mod) % mod;
        sm = (sm + x) % mod;
    }
    
    int div = ((n * (n - 1) % mod) * inv(2)) % mod;
    ans = (ans * inv(div)) % mod;

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