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
    vector<int> v(n), val[2];
    for(auto &x : v) {
        cin >> x;
        val[x > 0].push_back(x);
    }

    auto f = [&] (vector<int>& v) {
        int n = sz(v);
        for(int i = 1; i + 1 < n; i++) if(v[i] * v[i] != v[i - 1] * v[i + 1]) return false;
        return true;
    };

    
    if(sz(val[0]) && sz(val[1])) {
        vector<int> cur;
        sort(val[0].begin(), val[0].end());
        sort(val[1].rbegin(), val[1].rend());
        if(abs(sz(val[0]) - sz(val[1])) > 1) {cout << "No" << endl; return; }
        int id1 = 0, id2 = 0;
        if(sz(val[0]) == sz(val[1])) {
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) {
                    cur.push_back(val[1][id1++]);
                } else {
                    cur.push_back(val[0][id2++]);
                }
            }
            if(f(cur)) {cout << "Yes" << endl; return; }
            cur.clear();
            id1 = id2 = 0;
            for(int i = 0; i < n; i++) {
                if(i % 2 == 1) {
                    cur.push_back(val[1][id1++]);
                } else {
                    cur.push_back(val[0][id2++]);
                }
            }
            cout << (f(cur) ? "Yes" : "No") << endl;
        } else {
            int p = sz(val[1]) > sz(val[0]);
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) {
                    cur.push_back(val[p][id1++]);
                } else {
                    cur.push_back(val[!p][id2++]);
                }
            }
            cout << (f(cur) ? "Yes" : "No") << endl;
        }
    } else {
        sort(v.begin(), v.end());
        if(f(v)) {cout << "Yes" << endl; return; }
        reverse(v.begin(), v.end());
        cout << (f(v) ? "Yes" : "No") << endl;
    }
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