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
    int n, m; cin>>n>>m;
    vector<int> v(n);
    int mx = 0;
    for(auto &x : v) {cin>>x; mx = max(mx, x);}

    while(m--) {
        char op; cin>>op;
        int l, r; cin>>l>>r;
        if(op == '+') {
            if(l <= mx && mx <= r) {
                mx++;

            }
        } else {
            if(l <= mx && mx <= r) {
                mx--;
            }
        }
        cout<<mx<<" ";
    } cout<<endl;
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