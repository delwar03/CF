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
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    string s; cin>>s;

    vector<int> cur;

    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '0') {
            cur.push_back(v[i]);
        } else {
            vector<int> tmp;
            int j = i;
            while(s[j] == '1') tmp.push_back(v[j++]);
            tmp.push_back(v[j]);
            sort(tmp.begin(), tmp.end());
            for(int x : tmp) cur.push_back(x);
            i = j;
        }
    }

    if(sz(cur) < n) cur.push_back(v.back());

    // for(int x : cur) cerr<<x<<" "; cerr<<endl;

    cout<<(is_sorted(cur.begin(), cur.end()) ? "YES" : "NO")<<endl;
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