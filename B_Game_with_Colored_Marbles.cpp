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
    vector<int> freq(n + 1);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        freq[x] += 1;
    }

    priority_queue<pii> pq;

    for(int i = 1; i <= n; i++) {
        if(freq[i]) {
            pq.push({-freq[i], i});
        }
    }

    int ans = 0, f = 1;
    vector<int> got(n + 1);

    while(pq.size()) {
        auto [a, b] = pq.top();
        pq.pop();
        if(f) {
            got[b] += 1;
            if(a + 1) pq.push({a + 1, b});
        } else {
            if(a + 1) pq.push({a + 1, b});
        }
        f ^= 1;
    }

    for(int i = 1; i <= n; i++) {
        if(got[i]) {
            ans += (got[i] == freq[i] ? 2 : 1);
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