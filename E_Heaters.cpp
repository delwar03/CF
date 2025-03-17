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
    int n, r; cin>>n>>r;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> pf(n), pos;
    for(int i = 0; i < n; i++) {
        pf[i] = v[i] + (i - 1 >= 0 ? pf[i - 1] : 0);
    }
    for(int i = n - 1; i >= 0; i--) if(v[i]) pos.push_back(i);

    int prv = INF, cnt = -1;
    while(pos.size() && pos.back() <= r - 1) {
        prv = pos.back();
        pos.pop_back();
        cnt = 1;
    }

    for(int i = prv; i < n; i++) {
        int j = min(n - 1, prv + 2 * r - 1);
        if(i + r  >= n) break;
        int sm = pf[j] - pf[i];
        if(!sm) {cout<<-1<<endl; return; }
        while(pos.size() && pos.back() <= j) {
            prv = pos.back();
            pos.pop_back();
        }
        cnt += 1;
        i = prv - 1;
    }

    cout<<cnt<<endl;
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