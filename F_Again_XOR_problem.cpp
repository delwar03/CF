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
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int> v(k);
    for(int i = 0; i + k <= n; i++) if(s[i] == '1') {
        v[0] += 1;
        if(i + 1 < k) v[i + 1] -= 1;
    }
    // for(int i : v) cerr<<i<<" "; cerr<<endl;
    for(int i = n - k + 1, j = 1; i < n; i++, j++) if(s[i] == '1') {
        v[j] += 1;
        if(i + 1 < k) v[i + 1] -= 1;
    }
    for(int i = 1; i < k; i++) v[i] += v[i - 1];
    // for(int i : v) cerr<<i<<" "; cerr<<endl;
    int ct = 0;
    for(int x : v) ct += (x % 2 == 1);
    cout<<ct<<endl;
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