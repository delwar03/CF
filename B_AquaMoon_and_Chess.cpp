#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e7 + 10;
const int INF = 1e18 + 10;

int inv(int a, int m = mod) {
    if(a <= 1) return a;
    return m - (m / a) * inv(m % a) % m;
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    auto nCr = [&] (int n, int r) {
        if(n == 0 || r == 0) return 1LL;

        int res = 1;

        for(int i = 1; i <= r; i++) {
            res = (res * ((n - i + 1) * inv(i) % mod)) % mod;
        }
        return res;
    };

    int zeroCnt = 0, oneGroup = 0, cnt = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            zeroCnt++;
            oneGroup += cnt / 2;
            cnt = 0;

        } else {
            cnt++;
        }
    }
    oneGroup += cnt / 2;

    // cerr<<zeroCnt<<" "<<oneGroup<<endl;

    cout<<nCr(zeroCnt + oneGroup, oneGroup)<<endl;
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