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
    int sm = n * (n + 1) / 2;
    auto isSq = [&] (int x) {
        int rt = sqrtl(x);
        return rt * rt == x;
    };
    if(isSq(sm)) {cout<<-1<<endl; return; }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1LL);
    sm = 0;
    for(int i = 0; i < n; i++) {
        sm += v[i];
        if(isSq(sm)) {
            sm -= v[i];
            swap(v[i], v[i + 1]);
            sm += v[i];
        }
    }
    for(int i = 0; i < n; i++) cout<<v[i]<<" \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // for(int i = 1; i <= 100; i++) cerr<<i * (i + 1) / 2<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}