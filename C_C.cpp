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
    int n; cin >> n;
    int cnt = 0;
    for(int i = 2; i < 10; i++) if(n % i == 0) {
        int x = n / i;
        string a = to_string(n), b = to_string(x);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cnt += (a == b);
    }
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // for(int i = 1; i <= 100000; i++) {
    //     string s = to_string(i);
    //     sort(s.begin(), s.end());
    //     vector<int> ans;
    //     do {
    //         if(s[0] == '0') continue;
    //         int x = stol(s);
    //         if(x != i && i % x == 0) ans.push_back(x);
    //     } while(next_permutation(s.begin(), s.end()));

    //     if(sz(ans)) {
    //         cerr << i << " -> ";
    //         for(int x : ans) cerr << x << " "; cerr << endl;
    //     }
    // }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}