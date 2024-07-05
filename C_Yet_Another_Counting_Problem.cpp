#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e18 + 10;

void solve() {
    int a, b, q; cin>>a>>b>>q;

    int len = a * b;
    vector<int> pf(len + 1);

    for(int i = 1; i <= len; i++) {
        pf[i] = pf[i - 1];
        if((i % a) % b != (i % b) % a) {
            pf[i]++;
        }
    }

    auto val = [&] (int l) {
        int res = (l / len) * pf[len] + pf[l % len];
        return res;
    };

    auto query = [&] (int l, int r) {
        return val(r) - val(l - 1);
    };

    while(q--) {
        int l, r; cin>>l>>r;
        cout<<query(l, r)<<" ";
    }
    cout<<endl;
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