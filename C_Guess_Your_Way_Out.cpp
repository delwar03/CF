#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void call(int l, int r, int x, int ans, bool right) {
    if(l == r) {cout<<ans<<endl; return; }
    int tot = 0;
    int mid = (l + r) / 2;
    if(right) {
        if(x > mid) {
            call(mid + 1, r, x, ans + (r - l + 1), true);
        } else {
            call(l, mid, x, ans + 1, false);
        }
    } else {
        if(x > mid) {
            call(mid + 1, r, x, ans + 1, true);
        } else {
            call(l, mid, x, ans + (r - l + 1), false);
        }
    }
}

void solve() {
    int h, n; cin>>h>>n;
    call(1, (1LL << h), n, 0, true);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/