#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k, q; cin>>n>>k>>q;
    vector<int> a(k), b(k);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);


    while(q--) {
        int d; cin>>d;
        int time;

        if(d == n) {
            time = b.back();
        } else {
            int ind = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
            time = b[ind];
            d -= a[ind];
            time += d * (b[ind + 1] - b[ind]) / (a[ind + 1] - a[ind]);
        }

        cout<<time<<" \n"[q == 0];
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