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
    string s, t; cin >> s >> t;
    if(multiset<char>(s.begin(), s.end()) != multiset<char>(t.begin(), t.end())) {cout << "NO" << endl; return; }
    vector<int> freq(26);
    int mx = 0;
    for(auto c : s) freq[c - 'a']++, mx = max(mx, freq[c - 'a']);
    if(s == t) {cout << (mx > 1 ? "YES" : "NO") << endl; return; }
    int n = sz(s), cnt = 0;
    for(int i = 0; i < n; i++) cnt += (s[i] != t[i]);
    cout << (cnt == 2 ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}