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
    int n; string s, t; cin >> n >> s;
    for(auto c : s) t.push_back('#'), t.push_back(c);
    t.push_back('#');

    auto get = [&] (string s) {
        int n = sz(s);
        vector<int> p(n);
        for(int i = 0, l = 0, r = 1; i < n; i++) {
            if(i < r) p[i] = min(p[l + r - i], r - i);
            while(i - p[i] >= 0 && i + p[i] < n && s[i - p[i]] == s[i + p[i]]) p[i]++;
            if(i + p[i] > r) l = i - p[i], r = i + p[i];
        }
        return p;
    };

    auto d = get(t);
    int mxLen = 0, id = -1;
    for(int i = 0; i < sz(d); i++) if(d[i] > mxLen) mxLen = d[i], id = i;
    --mxLen;
    int cur = id / 2 - mxLen / 2;
    for(int i = 0; i < mxLen; i++) cout<<s[cur + i];
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