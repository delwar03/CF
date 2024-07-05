#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int x, n; cin>>x>>n;
    int m = x;
    set<int> primes;
    for(int i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            primes.insert(i);
            while(m % i == 0) m /= i;
        }
    }
    if(m > 1) primes.insert(m);
    // for(auto it : primes) cerr<<it<<" "; cerr<<endl;

    auto binPow = [&] (int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    };

    int ans = 1;

    assert(primes.size() < 10);

    for(auto p : primes) {
        int m = n;
        int cnt = 0;
        while(m) {
            cnt += m / p;
            m /= p;
        }
        ans = (ans * binPow(p, cnt)) % mod;
    }
    cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/