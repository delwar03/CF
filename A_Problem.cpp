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
    int n, c = 1;
    while(cin>>n) {
        cout<<"Case #"<<c++<<": \n";
        vector<int> v(n + 1);
        for(int i = 1; i <= n; i++) cin>>v[i];

        vector<int> BIT(n + 1);

        auto add = [&] (int x, int val) {
            for(int i = x; i <= n; i += i & -i) BIT[i] += val;
        };

        auto sum = [&] (int x) {
            int ret = 0;
            for(int i = x; i; i -= i & -i) ret += BIT[i];
            return ret;
        };

        auto qur = [&] (int l, int r) {
            if(l > r) return 0LL;
            return sum(r) - sum(l - 1);
        };

        for(int i = 1; i <= n; i++) add(i, v[i]);

        set<int> id;
        for(int i = 1; i <= n; i++) id.insert(i);
        
        int q; cin>>q;
        while(q--) {
            int t, x, y; cin>>t>>x>>y;
            if(x > y) swap(x, y);
            if(t == 0) {
                auto it = id.lower_bound(x);
                vector<int> del;
                while(it != id.end() && *it <= y) {
                    v[*it] = sqrtl(v[*it]);
                    add(*it, -qur(*it, *it) + v[*it]);
                    if(v[*it] == 1) del.push_back(*it);
                    ++it;
                }
                for(int i : del) id.erase(i);
            } else {
                cout<<qur(x, y)<<endl;
            }
        }
        cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case #"<<c++<<": \n";
        solve();
    }
}