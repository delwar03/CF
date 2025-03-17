#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, x; cin>>n>>x;
    vector<int> U(n), D(n);
    int sm = 0, mx = 0;
    for(int i = 0; i < n; i++) {
        cin>>U[i]>>D[i];
        sm += U[i] + D[i];
        mx = max(mx, U[i] + D[i]);
    }

    auto f = [&] (int h) {
        int L = max(0LL, h - D[0]), R = min(U[0], h);
        if(L > R) return false;
        for(int i = 1; i < n; i++) {
            int curL = max(0LL, h - D[i]), curR = min(U[i], h); 
            curL = max(curL, L - x);
            curR = min(curR, R + x);
            if(curL > curR) return false;
            L = curL, R = curR;
        }
        return true;
    };

    int lo = 0, hi = mx, best = -1;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(f(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    assert(~best);

    cout<<sm - n * best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}