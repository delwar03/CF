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
    int n, l, r; cin>>n>>l>>r;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    --l; --r;

    priority_queue<int> pq, pq1, pq2;
    int ans = 0, mn = INF;
    for(int i = l; i <= r; i++) ans += v[i], pq.push(v[i]);
    mn = ans;
    for(int i = r + 1; i < n; i++) pq1.push(-v[i]);
    int sm = 0, sm1 = 0;
    while(sz(pq) && sz(pq1)) {
        sm += pq.top(); pq.pop();
        sm1 -= pq1.top(); pq1.pop();
        mn = min(mn, ans - sm + sm1);
    }

    // cerr<<"ans: "<<mn<<endl;


    while(sz(pq)) pq.pop();
    while(sz(pq1)) pq1.pop();

    for(int i = l; i <= r; i++) pq.push(v[i]);
    for(int i = 0; i < l; i++) pq1.push(-v[i]);
    
    sm = 0, sm1 = 0;
    while(sz(pq) && sz(pq1)) {
        sm += pq.top(); pq.pop();
        sm1 -= pq1.top(); pq1.pop();
        mn = min(mn, ans - sm + sm1);
    }

    cout<<mn<<endl;
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