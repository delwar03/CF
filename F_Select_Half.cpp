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
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> lf(n), rt(n);
    for(int i = 0; i < n; i++) lf[i] = i - 1, rt[i] = i + 1;

    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) pq.push({v[i], i});

    vector<int> del(n);
    int sm = 0;

    for(int j = 0; j < n / 2; j++) {
        while(del[pq.top().S]) pq.pop();
        auto [x, i] = pq.top(); pq.pop();

        sm += x;
        v[i] = -x + (lf[i] >= 0 ? v[lf[i]] : -INF) + (rt[i] < n ? v[rt[i]] : -INF);
        pq.push({v[i], i});

        if(lf[i] >= 0) {
            del[lf[i]] = 1;
            lf[i] = lf[lf[i]];
            if(lf[i] >= 0)
                rt[lf[i]] = i;
        }
        if(rt[i] < n) {
            del[rt[i]] = 1;
            rt[i] = rt[rt[i]];
            if(rt[i] < n)
                lf[rt[i]] = i;
        }
    }

    cout<<sm<<endl;
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