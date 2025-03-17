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
    int n, k; cin>>n>>k;

    auto binPow = [&] (int a, int b) {
        if(b > 50) return INF;
        int ret = 1;
        while(b > 0) {
            if(b & 1) ret = ret * a;
            a = a * a;
            b >>= 1;
        }
        return ret;
    };

    if(k > binPow(2, n - 1)) {cout<<-1<<endl; return; }

    vector<int> ans(n);
    int l = 0, r = n - 1;
    k -= 1;

    for(int i = 1; i < n; i++) {
        int cur = binPow(2, n - i - 1);
        if(cur <= k) {
            ans[r--] = i;
            k -= cur;
        } else {
            ans[l++] = i;
        }
    }

    assert(l == r);
    ans[l] = n;

    for(int i = 0; i < n; i++) cout<<ans[i]<<" "; cout<<endl;
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