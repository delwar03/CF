#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    string a, b; cin>>a>>b;
    vector<int> pref(m + 1);
    for(int i = 0; i < m; i++) {
        pref[i + 1] = pref[i] + (b[i] - '0');
    }

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

    int ans = 0;

    for(int i = n - 1; i >= 0; i--) {
        int ind = m + 1 - n + i;
        if(ind >= 0) {
            int p = pref[ind];
            ans = (ans + (a[i] - '0') * binPow(2, n - 1 - i) * p) % mod;
        }
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