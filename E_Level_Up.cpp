#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n, q; cin>>n>>q;
    map<int, vector<int>> mp, lvl_up;
    vector<int> v(n + 1), rem;

    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        mp[v[i]].push_back(i);
        rem.push_back(i);
        lvl_up[i].push_back(0);
    }

    vector<int> BIT(2 * n);

    auto add = [&] (int i, int x) {
        for(; i <= n; i += i & -i) BIT[i] += x;
    };

    auto sum = [&] (int i) {
        int res = 0;
        for(; i; i -= i & -i) res += BIT[i];
        return res;
    };

    auto query = [&] (int l, int r) {
        return sum(r) - sum(l);
    };

    for(int i = 1; i <= n; i++) add(i, +1);

    for(int lvl = 1; lvl <= n; lvl++) {
        vector<int> nrem;

        for(auto x : rem) {
            int now = lvl_up[x].back();
            int lo = lvl_up[x].back(), hi = n, best = -1;

            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(query(now, mid) >= x) {
                    best = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            if(~best) {
                nrem.push_back(x);
                lvl_up[x].push_back(best);
            }
        }
        rem = nrem;

        for(auto i : mp[lvl]) add(i, -1);
    }


    while(q--) {
        int i, k; cin>>i>>k;
        cout<<((lvl_up[k].size() <= v[i] || lvl_up[k][v[i]] >= i) ? "YES" : "NO")<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
