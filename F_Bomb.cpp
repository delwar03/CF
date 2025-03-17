#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e9 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    auto getCnt = [&] (int x) {
        int ct = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] - x < 0) continue;
            int p = a[i] - x, d = b[i];
            ct += (p + d - 1) / d;
        }

        return ct;
    };

    auto getSum = [&] (int x) {
        int sm = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] - x < 0) continue;
            int p = a[i] - x, d = b[i];
            int t = (p + d - 1) / d;
            sm += t * (2 * a[i] + (t - 1) * (-d)) / 2;
        }

        return sm;
    };

    int l = 0, r = INF, best = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(getCnt(mid) <= k) {
            best = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    int cnt = getCnt(best);
    int sum = getSum(best);

    int ans = sum + (k - cnt) * best;

    cout<<ans<<endl;
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
