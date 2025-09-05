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
    auto ask = [&] (string s) {
        cout<<s<<endl;
        int b, c; cin>>b>>c;
        return pii{b, c};
    };

    string tmp(4, '0');
    auto p = ask(tmp);
    int b = p.F, c = p.S;
    for(int i = 0; i < 4; i++) {
        for(char j = '1'; j <= '9'; j++) {
            tmp[i] = j;
            auto [bb, cc] = ask(tmp);
            if(bb < b) {tmp[i] = '0'; break; }
            if(bb > b) {b = bb; break; }
        }
    }
    cout<<tmp<<endl;
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