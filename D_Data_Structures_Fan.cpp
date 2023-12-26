#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    string s; cin>>s;
    int pref[n][2];// i[0] i[1]
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') one ^= v[i];
        else zero ^= v[i];
        pref[i][0] = zero;
        pref[i][1] = one;
    }

    int q; cin>>q;
    while(q--) {
        int ty; cin>>ty;
        if(ty == 1) {
            int l, r; cin>>l>>r;
            l--; r--;
            int z1 = pref[r][0];
            if(l) z1 ^= pref[l - 1][0];
            int o1 = pref[r][1];
            if(l) o1 ^= pref[l - 1][1];

            one ^= o1;
            one ^= z1;

            zero ^= z1;
            zero ^= o1;
        } else {
            int x; cin>>x;
            if(x == 1) cout<<one<<" ";
            else cout<<zero<<" ";
        }
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 