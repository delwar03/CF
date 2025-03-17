#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    set<vector<int>> all_comb;
    vector<int> perm(6);
    iota(perm.begin(), perm.end(), 0);
    
    do {
        if(perm[0] != 0) break;
        vector<int> p1 = {perm[0], perm[1], perm[2]};
        vector<int> p2 = {perm[3], perm[4], perm[5]};
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        vector<int> cur;
        for(auto x : p1) cur.push_back(x);
        for(auto x : p2) cur.push_back(x);
        all_comb.insert(cur);

    } while(next_permutation(perm.begin(), perm.end()));

    // cerr<<"comb: \n";
    // for(auto x : all_comb) {
    //     for(auto y : x) cerr<<y<<" "; cerr<<endl;
    // }

    auto isValid = [&] (int a, int b, int c) {
        return c < a + b;
    };

    auto query = [&] (int l, int r) {
        if(r - l + 1 >= 100) return true;

        vector<int> tmp;
        for(int i = l; i <= r; i++) tmp.push_back(v[i]);
        sort(tmp.begin(), tmp.end());

        int ct = 0;
        for(int i = 0; i + 2 < (int) tmp.size() && ct < 2; i++) {
            if(isValid(tmp[i], tmp[i + 1], tmp[i + 2])) {
                ct++;
                i += 2;
            }
        }

        if(ct == 2) return true;

        for(int i = 0; i + 5 < (int) tmp.size(); i++) {
            for(auto comb : all_comb) {
                if(isValid(tmp[i + comb[0]], tmp[i + comb[1]], tmp[i + comb[2]]) && isValid(tmp[i + comb[3]], tmp[i + comb[4]], tmp[i + comb[5]])) {
                    return true;
                }
            }
        }

        return false;
    };

    while(q--) {
        int l, r; cin>>l>>r;
        --l; --r;
        cout<<(query(l, r) ? "YES" : "NO")<<endl;
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
