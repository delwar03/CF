#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    auto u = v;
    sort(u.begin() + 1, u.end());

    for(int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
        u[i] += u[i - 1];
    }

    int q; cin>>q;
    while(q--) {
        int ty, l, r; cin>>ty>>l>>r;
        cout<<(ty == 1 ? v[r] - v[l - 1] : u[r] - u[l - 1])<<endl;
    }
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