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
    int n, m, L; cin>>n>>m>>L;
    vector<pair<int, int>> H(n), V(m);
    for(auto &[a, b] : H) cin>>a>>b;
    for(auto &[a, b] : V) cin>>a>>b;

    // for(auto [a, b] : V) cerr<<a<<" "<<b<<endl; cerr<<endl;

    int cnt = 0, cur = 1;
    priority_queue<int> pq;
    int i = 0, j = 0;
    for(int i = 0, j = 0; i < n; i++) {
        auto [l, r] = H[i];
        int len = r - l + 1;
        while(j < m && V[j].F < l) {
            pq.push(V[j].S);
            j++;
        }
        while(!pq.empty() && cur <= len) {
            cur += pq.top();
            pq.pop();
            cnt++;
        }
        // cerr<<cnt<<endl;
        // cerr<<"l: "<<l<<", r: "<<r<<", cur: "<<cur<<endl;
        if(cur <= len) {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<cnt<<endl;
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