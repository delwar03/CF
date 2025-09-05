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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    map<int, pii> pos;
    for(int i = 0; i < n; i++) pos[a[i]] = {0, i};
    for(int i = 0; i < n; i++) pos[b[i]] = {1, i};

    vector<pii> ans;
    for(int i = 0; i < n; i++) {
        auto [f, id] = pos[i + 1];
        if(f == 0) {
            if(id > i) {
                for(int j = id - 1; j >= i; j--) {
                    ans.push_back({1, j});
                    swap(a[j], a[j + 1]);
                    swap(pos[a[j]], pos[a[j + 1]]);
                }
            } else {
                for(int j = id; j < i; j++) {
                    ans.push_back({1, j});
                    swap(a[j], a[j + 1]);
                    swap(pos[a[j]], pos[a[j + 1]]);
                }
            }
        } else {
            if(id > i) {
                for(int j = id - 1; j >= i; j--) {
                    ans.push_back({2, j});
                    swap(b[j], b[j + 1]);
                    swap(pos[b[j]], pos[b[j + 1]]);
                }
            } else {
                for(int j = id; j < i; j++) {
                    ans.push_back({2, j});
                    swap(b[j], b[j + 1]);
                    swap(pos[b[j]], pos[b[j + 1]]);
                }
            }
            ans.push_back({3, i});
            auto [f1, id1] = pos[a[i]];
            auto [f2, id2] = pos[b[i]];
            pos[a[i]] = {!f1, id1};
            pos[b[i]] = {!f2, id2};
            swap(a[i], b[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        auto [f, id] = pos[n + i + 1];
        if(id > i) {
            for(int j = id - 1; j >= i; j--) {
                ans.push_back({2, j});
                swap(b[j], b[j + 1]);
                swap(pos[b[j]], pos[b[j + 1]]);
            }
        } else {
            for(int j = id; j < i; j++) {
                ans.push_back({2, j});
                swap(b[j], b[j + 1]);
                swap(pos[b[j]], pos[b[j + 1]]);
            }
        }
    }

    cout << sz(ans) << endl;
    for(auto [a, b] : ans) cout << a << " " << b + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}