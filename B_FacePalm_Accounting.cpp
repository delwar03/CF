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
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    int mn = INF;
    for(auto &x : v) {
        cin>>x;
        mn = min(mn, x);
    }

    int ans = 0, sm = 0;
    for(int i = 0; i < k - 1; i++) sm += v[i];

    for(int i = k - 1, j = n - 1; i < n; i++) {
        sm += v[i];
        if(sm >= 0) {
            sm++;
            ans += sm;
            j = i;
            while(j >= i - (k - 1) && sm) {
                if(v[j] - sm >= mn) {
                    v[j] -= sm;
                    sm = 0;
                } else {
                    sm -= (v[j] - mn);
                    v[j] = mn;
                    j--;
                }
            }
            assert(sm == 0);
            sm = -1;
        }
        sm -= v[i - (k - 1)];
    }

    cout<<ans<<endl;
    for(int i = 0; i < n; i++) cout<<v[i]<<" \n"[i == n - 1];
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