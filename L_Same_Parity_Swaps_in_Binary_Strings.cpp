#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    string s; cin>>s;
    vector<vector<int>> cnt(2, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cnt[i % 2][s[i] - '0']++;
    }

    int ind = 0, ans = 0;
    while(ind < n) {
        if(cnt[0][0] && cnt[1][1]) {
            cnt[0][0]--, cnt[1][1]--;
            ind += 2, ans++;
        } else if(cnt[0][0]) {
            cnt[0][0]--;
            ind++;
            swap(cnt[0], cnt[1]);
        } else {
            cnt[0][1]--;
            ind++;
            swap(cnt[0], cnt[1]);
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}