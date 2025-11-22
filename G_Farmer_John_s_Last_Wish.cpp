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

vector<int> siv[N];

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int mxVal = 0;
    for(auto &x : v) cin >> x, mxVal = max(mxVal, x);
    
    // for(int x : v) cerr << x << " "; cerr << endl;
    
    int g = 0, mx = 0;
    vector<int> cnt(mxVal + 1);

    for(int i = 0; i < n; i++) {
        if(g != gcd(g, v[i])) {
            g = gcd(g, v[i]);
            cnt = vector<int>(mxVal + 1);
            mx = 0;
            for(int j = 0; j < i; j++) {
                for(int d : siv[v[j] / g]) {
                    mx = max(mx, ++cnt[d]);
                }
            }
        }

        for(int d : siv[v[i] / g]) {
            mx = max(mx, ++cnt[d]);
        }
        cout << mx << " \n"[i == n - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(sz(siv[i])) continue;
        for(int j = i; j < N; j += i) {
            siv[j].push_back(i);
        }
    }

    // for(int i = 2; i <= 100; i++) {
    //     cerr << i << " -> ";
    //     for(int j : siv[i]) cerr << j << " "; cerr << endl;
    // }

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}