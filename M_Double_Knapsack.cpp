#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i], a[i] += a[i - 1];
    for(int i = 1; i <= n; i++) cin>>b[i], b[i] += b[i - 1];

    auto print = [&] (int l, int r) {
        cout<<r - l<<endl;
        for(int i = l + 1; i <= r; i++) cout<<i<<" \n"[i == r];
    };

    int f = 0;
    if(b[n] < a[n]) swap(a, b), f = 1;

    vector<pii> vis(n, {-1, -1});
    for(int i = 0, j = 0; i <= n; i++) {
        while(j + 1 <= n && b[j + 1] <= a[i]) j++;
        int dif = a[i] - b[j];
        if(vis[dif] != pii{-1, -1}) {
            if(f) {
                print(vis[dif].S, j);
                print(vis[dif].F, i);
            } else {
                print(vis[dif].F, i);
                print(vis[dif].S, j);
            }
            return;
        }
        vis[dif] = {i, j};
    }
    cout<<-1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}