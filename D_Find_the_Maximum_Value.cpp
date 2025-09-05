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
    string s; getline(cin, s);
    // cerr<<s<<endl;
    vector<int> v;
    int sz = sz(s);
    for(int i = 0; i < sz; i++) {
        int cur = 0, j = i;
        while(j < sz && s[j] != ' ') {
            cur *= 10;
            cur += (s[j] - '0');
            j++;
        }
        v.push_back(cur);
        i = j;
    }
    
    int curSz = sz(v) - 1, mx = 0, f = 0;
    for(int i = 0; i <= curSz; i++) {
        if(!f && v[i] == curSz) {f = 1; continue; }
        mx = max(mx, v[i]);
    }

    cout<<mx<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    cin.ignore();
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}