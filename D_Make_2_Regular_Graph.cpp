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
    int n, m; cin >> n >> m;
    set<pii> st;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        st.insert({--u, --v}), st.insert({v, u});
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);

    auto get = [&] (vector<int> v) {
        int cnt = 0, n = sz(v);
        for(int i = 0; i < n; i++) {
            if(!st.count({v[i], v[(i + 1) % n]})) {
                cnt += 1;
            } else {
                cnt -= 1;
            }
        }
        return cnt;
    };

    int ans = INF;

    do {
        for(int  mask = 0; mask < (1LL << n); mask++) {
            vector<vector<int>> comp;
            int cnt = m;
            for(int i = 0; i < n; i++) {
                int j = i;
                while(j < n && !(mask >> j & 1)) j++;
                if(j - i <= 1) {cnt = INF; break; }
                vector<int> tmp;
                for(int k = i; k <= j; k++) tmp.push_back(ord[k]);
                comp.push_back(tmp);
                i = j;
            }

            for(auto it : comp) cnt += get(it);
            ans = min(ans, cnt);
        }
    } while(next_permutation(ord.begin(), ord.end()));
    
    cout << ans << endl;
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