#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define ff first
#define ss second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k ; cin >> n >>k ;
    vector<pii> v;
    for (int i=0 ; i<n ;i++) {
        int x,y ; cin >> x>>y;
        v.push_back ({x,0});
        v.push_back ({y,1});
    }
    sort (v.begin () , v.end ());

  //  for (auto it :v) cerr << it.ff <<" " << it.ss <<"\n";
    vector <pii> ans;
    int cnt = 0;

    for (auto it : v) {

        if (it.ss == 0 && cnt == k - 1) {
            ans.push_back ({it.ff , it.ff});
        }
        else if (it.ss == 1 && cnt == k ) {
            ans.back().ss = it.ff;
        }
        if (it.ss == 0) cnt ++;
        else cnt--;
    }

    cout << ans.size () <<"\n";
    for (auto it :ans) cout << it.ff <<" " << it.ss <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}