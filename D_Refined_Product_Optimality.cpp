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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int inv(int a) {
  return a <= 1 ? a : mod - (mod / a) * inv(mod % a) % mod;
}

void solve() {
    int n, q; cin>>n>>q;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    o_set<pii> aa, bb;

    for(int i = 0; i < n; i++) {
        aa.insert({a[i], i});
        bb.insert({b[i], i});
    }

    int ans = 1;

    for(int i = 0; i < n; i++) {
        ans = (ans * (min((*aa.find_by_order(i)).F, (*bb.find_by_order(i)).F))) % mod;
    }

    cout<<ans<<" ";

    for(int j = 1; j <= q; j++) {
        int f, i; cin>>f>>i;
        --i;
        if(f == 1) {
            int id = aa.order_of_key({a[i], n}) - 1;

            // cerr<<id<<endl;

            ans = (ans * inv(min((*aa.find_by_order(id)).F, (*bb.find_by_order(id)).F))) % mod;
            if(id + 1 < n)
                ans = (ans * inv(min((*aa.find_by_order(id + 1)).F, (*bb.find_by_order(id + 1)).F))) % mod;

            aa.erase({a[i], i});
            a[i] += 1;
            aa.insert({a[i], i});

            ans = (ans * (min((*aa.find_by_order(id)).F, (*bb.find_by_order(id)).F))) % mod;
            if(id + 1 < n)
                ans = (ans * (min((*aa.find_by_order(id + 1)).F, (*bb.find_by_order(id + 1)).F))) % mod;
        } else {
            int id = bb.order_of_key({b[i], n}) - 1;

            // cerr<<id<<endl;

            ans = (ans * inv(min((*aa.find_by_order(id)).F, (*bb.find_by_order(id)).F))) % mod;
            if(id + 1 < n)
                ans = (ans * inv(min((*aa.find_by_order(id + 1)).F, (*bb.find_by_order(id + 1)).F))) % mod;

            bb.erase({b[i], i});
            b[i] += 1;
            bb.insert({b[i], i});

            ans = (ans * (min((*aa.find_by_order(id)).F, (*bb.find_by_order(id)).F))) % mod;
            if(id + 1 < n)
                ans = (ans * (min((*aa.find_by_order(id + 1)).F, (*bb.find_by_order(id + 1)).F))) % mod;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
