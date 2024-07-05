#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;
int pwr[N], hsh[N];

void solve() {
    string s; cin>>s;
    int n = s.size();

    hsh[0] = s[0];
    for(int i = 1; i < n; i++) {
        hsh[i] = (hsh[i - 1] * prm + s[i]) % mod;
    }

    auto getHash = [&] (int l, int r) {
        return (hsh[r] - ((l - 1 >= 0 ? hsh[l - 1] : 0) * pwr[r - l + 1] % mod) + mod) % mod;
    };

    if(n & 1) {
        cout<<0<<endl;
    } else {
        int ans = 0;

        for(int i = 0; i < n / 2 - 1; i++) {
            int j = n / 2 - (i + 1);
            if(getHash(0, i) == getHash(i + 1, 2 * i + 1) and getHash(2 * i + 2, i + n / 2) == getHash(i + n / 2 + 1, n - 1)) ans++;
        }
        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pwr[0] = 1;
    for(int i = 1; i < N; i++) {
        pwr[i] = (prm * pwr[i - 1]) % mod;
    }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/