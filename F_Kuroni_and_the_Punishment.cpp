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

    auto get = [&] (int x) {
        if(x <= 1) return INF;
        int tmp = x;
        vector<int> di;
        for(int i = 2; i * i <= tmp; i++) {
            if(tmp % i == 0) {
                di.push_back(i);
                while(tmp % i == 0) tmp /= i;
            }
        }
        if(tmp > 1) di.push_back(tmp);

        auto f = [&] (int d) {
            int sm = 0;
            for(int x : v) {
                if(d > x) {
                    sm += d - x;
                } else {
                    sm += min(x % d, d - x % d);
                }
            }
            return sm;
        };

        int cur = INF;
        for(int d : di) {
            cur = min(cur, f(d));
        }

        return cur;
    };

    int it = 30, ans = INF;
    while(it--) {
        int id = rng() % n;
        ans = min(ans, get(v[id]));
        ans = min(ans, get(v[id] + 1));
        ans = min(ans, get(v[id] - 1));
    }

    cout<<ans<<endl;
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