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
    int n, k; string s; cin >> n >> k >> s;
    int m = n / k, need = (k + 1) / 2;

    // cerr << m << " " << need << endl;

    vector<int> fq(26);
    for(auto c : s) fq[c - 'a'] += 1;
    
    string ans(m, '?');
    for(int i = 0; i < m; i++) {
        int cur = 0;
        for(int j = 0; j < 26; j++) if(fq[j]) {
            if(cur + fq[j] >= need) {
                ans[i] = char(j + 'a');
                fq[j] -= (need - cur);
                break;
            }
            cur += fq[j];
            fq[j] = 0;
        }
    }

    cout << ans << endl;
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