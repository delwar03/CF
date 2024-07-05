#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int inv(int a, int m = mod) {
    if(a <= 1) return a;
    return m - (m / a) * inv(m % a) % mod;
}

void solve() {
    int l, r, k; cin>>l>>r>>k;
    int x = 9 / k;

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

    auto sum = [&] (int n) {

        if(n <= 0) return 0LL;

        return (binPow(x + 1, n) - 1 + mod) % mod;
    };

    cout<<(sum(r) - sum(l) + mod) % mod<<endl;
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