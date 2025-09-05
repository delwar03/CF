#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
// #define endl '\n'
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

    auto ask = [&] (string s) {
        cout<<s<<endl;
        int x; cin>>x;
        return x;
    };

    string tmp(n, '?');
    for(int iter = 0; iter < 490; iter++) {
        for(int i = 0; i < n; i++) tmp[i] = '0' + rng() % 2;
        int x = ask(tmp);
        if(x == n) return;
        if(x == n / 2) break;
    }

    vector<int> f(n);
    f[0] = 1;
    for(int i = 1; i < n; i++) {
        tmp[0] ^= '0' ^ '1';
        tmp[i] ^= '0' ^ '1';
        int x = ask(tmp);
        if(x == n) return;
        f[i] = (x == 0);
        tmp[0] ^= '0' ^ '1';
        tmp[i] ^= '0' ^ '1';
    }

    // let tmp[0] is correct
    for(int i = 0; i < n; i++) if(!f[i]) tmp[i] ^= '0' ^ '1';
    if(ask(tmp) == n) return;
    for(int i = 0; i < n; i++) tmp[i] ^= '0' ^ '1';
    ask(tmp);
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