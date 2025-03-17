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

int cnt[N];

void solve() {
    int n, m; cin>>n>>m;
    vector<int> v(m);
    for(int &x : v) cin>>x;

    vector<int> ans;

    for(int i = 1; i <= n; i++) {
        int ind = m - cnt[i] - 1;
        if(ind < 0) {
            cout<<-1<<endl;
            return;
        }
        ans.push_back(v[ind]);
    }

    for(auto it : ans) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(!cnt[i]) {
            for(int j = i; j < N; j += i) {
                cnt[j] = cnt[j / i] + 1;
            }
        } 
    }

    // for(int i = 0; i <= 100; i++) cerr<<i<<" -> "<<cnt[i]<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}