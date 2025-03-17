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
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int cnt = 0;
    string ans;
    int i;
    for(i = 0; i < n; i++) {
        if(s[i] == '1') {
            cnt++;
            while(s[i] == '1') ans += s[i++];
            i--;
        } else {
            ans += s[i];
        }
        if(cnt == k - 1) break;
    }

    int f = 0;
    string tmp;

    for(i += 1; i < n; i++) {
        if(!f) {
            while(s[i] != '1') tmp += s[i++];
            i--;
            f = 1;
        } else {
            if(sz(tmp)) {
                while(s[i] == '1') ans += s[i++];
                i--;
                ans += tmp;
                tmp.clear();
            } else {
                ans += s[i];
            }
        }

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