#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());

    while(q--) {
        int x, k; cin>>x>>k;
        int l = 0, r = INF, best = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int cnt = upper_bound(v.begin(), v.end(), x + mid) - lower_bound(v.begin(), v.end(), x - mid);
            if(cnt >= k) {
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout<<best<<endl;
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