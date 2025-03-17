#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    vector<int> v(n), in(n + 1);
    for(auto &x : v) cin>>x, in[x] += 1;

    vector<int> rem;
    for(int i = 1; i <= n; i++) {
        assert(0 <= in[i] && in[i] <= 1);
        if(!in[i]) rem.push_back(i);
    }

    int prvInd = -1;

    for(int i = 0; i < n; i++) {
        if(!v[i]) {
            int cur = rem.back(); rem.pop_back();
            v[i] = cur;
            if(i + 1 == cur) {
                if(~prvInd) {
                    swap(v[i], v[prvInd]);
                } else {
                    v[i] = rem.back(); rem.pop_back();
                    rem.push_back(cur);
                }
            }
            prvInd = i;
        }
    }

    for(auto it : v) cout<<it<<" "; cout<<endl;
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