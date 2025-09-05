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

vector<string> cand;

void solve() {
    for(int a = 0; a < 10; a++) 
        for(int b = 0; b < 10; b++) 
            for(int c = 0; c < 10; c++) 
                for(int d = 0; d < 10; d++) if(sz(set<int>({a, b, c, d})) == 4) {
                    string tmp = "";
                    tmp += to_string(a);
                    tmp += to_string(b);
                    tmp += to_string(c);
                    tmp += to_string(d);
                    cand.push_back(tmp);
                }
    
    // cerr<<sz(cand)<<endl;

    auto ask = [&] (string s) {
        cout<<s<<endl;
        pii ret; cin>>ret.F>>ret.S;
        return ret;
    };

    auto get = [&] (string s, string t) {
        pii ret;
        vector<bool> vis(10);
        for(int i = 0; i < 4; i++) {
            ret.F += (s[i] == t[i]);
            vis[s[i] - '0'] = 1;
        }
        for(int i = 0; i < 4; i++) {
            ret.S += (s[i] != t[i] && vis[t[i] - '0']);
        }
        return ret;
    };

    auto upd = [&] (pii cur) {
        vector<string> tmp;
        for(int i = 1; i < sz(cand); i++) {
            if(get(cand[i], cand[0]) == cur) tmp.push_back(cand[i]);
        }
        return tmp;
    };

    while(sz(cand)) {
        random_shuffle(cand.begin(), cand.end());
        auto cur = ask(cand[0]);
        if(cur.F == 4) return;
        cand = upd(cur);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(2333333);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}