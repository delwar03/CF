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
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto f = [&] (int x) {
        int cnt = 0, f = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] <= x) continue;
            if(s[i] == 'B') {
                if(!f) cnt++, f = 1;
            } else {
                f = 0;
            }
        }
        return cnt <= k;
    };

    int lo = 0, hi = INF, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(f(mid)) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}