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
    int n, k; cin>>n>>k;
    vector<int> v(n), freq(25), last(25);
    int mx = 0;
    for(auto &x : v) cin>>x, freq[x]++, mx = max(mx, freq[x]);
    for(int i = 0; i < n; i++) last[v[i]] = i;
    if(freq[k] == mx) {
        cout<<0<<endl; 
    } else {
        freq = vector<int>(25, 0);
        mx = 0;
        for(int i = 0; i < n; i++) {
            freq[v[i]]++, mx = max(mx, freq[v[i]]);
            if(mx == freq[k]) {
                cout<<1<<endl;
                return;
            }
        }
        freq = vector<int>(25, 0);
        mx = 0;
        for(int i = n - 1; i >= 0; i--) {
            freq[v[i]]++, mx = max(mx, freq[v[i]]);
            if(mx == freq[k]) {
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
    }
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