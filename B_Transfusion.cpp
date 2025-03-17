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
    vector<int> v(n);
    int sm = 0;
    for(auto &x : v) cin>>x, sm += x;

    if(sm % n) {cout<<"NO"<<endl; return; }
    
    int d = sm / n;
    int sm1 = 0, sm2 = 0, ct1 = 0, ct2 = 0;
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            sm1 += v[i];
            ct1 += 1;
        } else {
            sm2 += v[i];
            ct2 += 1;
        }
    }

    int f = (sm1 % ct1 == 0 && sm2 % ct2 == 0 && sm1 / ct1 == d && sm2 / ct2 == d);

    cout<<(f ? "YES" : "NO")<<endl;
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