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

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    map<pii, int> mp;
    pii cur = {0, 0};
    mp[cur] = 0;

    int l = -1, r = n;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'D') {
            cur.F += 1;
        } else if(s[i] == 'U') {
            cur.F -= 1;
        } else if(s[i] == 'R') {
            cur.S += 1;
        } else {
            cur.S -= 1;
        }

        if(mp.count(cur)) {
            if(i - mp[cur] < r - l) {
                l = mp[cur];
                r = i;
            }
        }

        mp[cur] = i + 1;
    }

    if(~l) {
        cout<<l + 1<<" "<<r + 1<<endl;
    } else {
        cout<<"-1"<<endl;
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