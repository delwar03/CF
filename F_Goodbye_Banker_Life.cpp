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
    for(int i = 0; i < n; i++) cout<<((n - 1 & i) == i ? k : 0)<<" \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int kk = 1;
    // vector<int> prv{kk};

    // for(int j = 0; j <= 100; j++) {
    //     cerr<<j + 1<<" -> ";
    //     for(int x : prv) cerr<<x<<" "; cerr<<endl;
    //     vector<int> cur{kk};
    //     for(int i = 0; i + 1 < sz(prv); i++) {
    //         cur.push_back(prv[i] ^ prv[i + 1]);
    //     }
    //     cur.push_back(prv.back());
    //     swap(cur, prv);
    // }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}