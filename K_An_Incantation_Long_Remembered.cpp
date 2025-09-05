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
    vector<string> v(n);
    for(auto &x : v) cin >> x;
    vector<int> id(26, -1);
    for(int i = 0; i < n; i++) {
        for(char c : v[i]) {
            id[c - 'a'] = i;
        }
    }
    string s; cin >> s;

    int cnt = 1;
    stack<pii> stk;
    for(char c : s) {
        int i = id[c - 'a'];
        if(i == -1) {cout << "No" << endl; return; }
        if(c == v[i][0]) {
            cnt++;
            if(sz(v[i]) > 1) stk.push({i, 1});
        } else {
            if(sz(stk) && stk.top().F == i && v[i][stk.top().S] == c) {
                stk.top().S++;
                if(stk.top().S == sz(v[i])) stk.pop();
            } else {
                cout << "No" << endl;
                return;
            }
        }
    }

    if(sz(stk)) {cout << "No" << endl; return; }
    cout << "Yes" << endl;
    cout << cnt << endl;
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