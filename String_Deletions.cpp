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
    int n; string s; cin >> n >> s;
    pii zero{-1, -1}, one{-1, -1};
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            if(zero.F == -1) zero.F = i;
            zero.S = i;
        } else {
            if(one.F == -1) one.F = i;
            one.S = i;
        }
    }

    if(zero.F > one.F) swap(zero, one);

    if(zero.F == zero.S || one.F == one.S) {
        int cnt = 0;
        if(zero.F != -1) {
            for(int i = zero.F; i <= zero.S; i++) {
                if(s[i] != s[zero.F]) cnt++;
            }
        }
        if(one.F != -1) {
            for(int i = one.F; i <= one.S; i++) {
                if(s[i] != s[one.F]) cnt++;
            }
        }
        cout << n - cnt << endl;
        return;
    }

    
    // cerr << "HI" << endl;
    // cerr << zero.F << " " << zero.S << endl;
    // cerr << one.F << " " << one.S << endl;

    int cnt = 0;
    for(int i = zero.F; i <= zero.S; i++) {
        if(s[i] != s[zero.F]) cnt++;
    }
    for(int i = one.F; i <= one.S; i++) {
        if(s[i] != s[one.F]) cnt++;
    }
    
    if((zero.F <= one.F && one.S <= zero.S) || (zero.S < one.F)) {
        cout << n - cnt << endl;
    } else {
        cout << n - cnt + 1 << endl;
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