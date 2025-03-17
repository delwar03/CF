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
    string s; cin>>s;
    int n = sz(s);

    auto cng = [&] (char ch) {
        if('a' <= ch && ch <= 'z') return (char) toupper(ch);
        return (char) tolower(ch);
    };

    int q; cin>>q;
    while(q--) {
        int i; cin>>i;
        --i;
        int ind = i % n, x = i / n;
        x = __builtin_popcountll(x);
        cout<<(x & 1 ? cng(s[ind]) : s[ind])<<" \n"[q == 0];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}