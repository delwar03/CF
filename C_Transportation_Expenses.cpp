#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    if(accumulate(v.begin(), v.end(), 0LL) <= k) {cout<<"infinite"<<endl; return; }

    auto f = [&] (int x) {
        int cost = 0;
        for(int i = 0; i < n; i++) {
            cost += min(x, v[i]);
        }
        return cost <= k;
    };

    int l = 1, r = INF, best = -1;

    while(l <= r) {
        int mid = (l + r) >> 1;
        if(f(mid)) {
            best = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout<<best<<endl;
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