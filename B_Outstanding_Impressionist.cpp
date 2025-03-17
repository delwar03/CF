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
    int n; cin>>n;
    vector<pii> ran(n);
    vector<int> pf(2 * n + 1), uni(2 * n + 1);
    for(auto &[l, r] : ran) {
        cin>>l>>r;
        if(l == r) pf[l] = 1, uni[l] += 1;
    }

    for(int i = 1; i <= 2 * n; i++) pf[i] += pf[i - 1];

    for(auto [l, r] : ran) {
        if(l == r) {
            cout<<(uni[l] == 1 ? '1' : '0');
        } else {
            cout<<(pf[r] - pf[l - 1] == r - l + 1 ? '0' : '1');
        }
    } cout<<endl;
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