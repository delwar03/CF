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
    string s; cin>>s;
    int n = sz(s);
    vector<int> pos[4];

    auto get = [&] (char ch) {
        if(ch == 'a') return 1LL;
        if(ch == 'b') return 2LL;
        if(ch == 'c') return 3LL;
        else assert(false);
    };

    for(int i = 0; i < n; i++) pos[get(s[i])].push_back(i);

    // for(int i = 1; i <= 3; i++) {
    //     for(int j : pos[i]) cerr<<j<<" "; cerr<<endl;
    // }

    int ans = INF;

    for(int i = 0; i + 1 < n; i++) {
        int f = get(s[i]) ^ get(s[i + 1]);
        auto it = lower_bound(pos[f].begin(), pos[f].end(), i);
        if(it != pos[f].end()) ans = min(ans, *it - i + 1);
    }

    cout<<ans<<endl;
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