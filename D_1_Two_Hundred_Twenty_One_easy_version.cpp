#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

int prime[N];
set<int> st;

void solve() {
    int n, q; cin>>n>>q;
    string s; cin>>s;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        v.push_back(s[i] == '+' ? 1 : -1);
        if(i & 1) v[i] = -v[i];
    }

    vector<int> pf(n + 1);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] + v[i];
    }

    while(q--) {
        int l, r; cin>>l>>r;
        if(pf[r] - pf[l - 1] == 0) {
            cout<<0<<endl;
        } else {
            if((r - l + 1) & 1) {
                cout<<1<<endl;
            } else {
                cout<<2<<endl;
            }
        }
    }
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