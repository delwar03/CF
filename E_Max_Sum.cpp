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
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0LL);
    sort(ind.begin(), ind.end(), [&] (int i, int j) {
        return a[i] < a[j];
    });

    // for(auto i : ind) cerr<<b[i]<<" "; cerr<<endl;

    priority_queue<int> pq;

    int sm = 0, ans = INF;
    for(int i = 0; i < n; i++) {
        pq.push(b[ind[i]]);
        sm += b[ind[i]];
        if(pq.size() > k) {
            sm -= pq.top();
            pq.pop();
        }
        if(pq.size() == k) {
            ans = min(ans, sm * a[ind[i]]);
        }
    }

    cout<<ans<<endl;
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

/*
i/p: 
o/p: 
*/