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
    int n;
    string s, t; cin>>n>>s;

    auto get = [&] (string s) {
        int sm = 0, tmp = 0;
        for(auto ch : s) {
            if(ch == '+') sm += tmp, tmp = 0;
            else tmp = tmp * 10 + (ch - '0');
        }
        if(tmp) sm += tmp;
        return sm;
    };

    vector<string> ans(3);

    do {
        t = s;
        for(int j = 0; j < 3; j++) {
            string cur;
            for(int i = 0; i < sz(t); i++) {
                if(i) cur.push_back('+');
                cur.push_back(t[i]);
            }
            ans[j] = cur;
            int sm = get(cur);
            t = to_string(sm);
        }
    } while(sz(t) != 1);

    for(auto x : ans) cout<<x<<endl;
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