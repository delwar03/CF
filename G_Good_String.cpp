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

vector<string> ord;

void solve() {
    string s; cin>>s;
    int n = sz(s);
    vector<int> freq(10);
    int mx = 0;
    for(auto ch : s) {
        freq[ch - '0'] += 1;
        mx = max(mx, freq[ch - '0']);
    }

    auto f = [&] (string tmp) {
        int i = 0, cnt = 0;
        for(auto ch : s) {
            if(ch == tmp[i]) {
                cnt += 1;
                i += 1;
                i %= 2;
            }
        }
        if(cnt & 1) cnt -= 1;
        return cnt;
    };

    int ans = n - mx;

    for(auto it : ord) {
        ans = min(ans, n - f(it));
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(char i = '0'; i <= '9'; i++) {
        for(char j = '0'; j <= '9'; j++) {
            if(i == j) continue;
            string tmp;
            tmp.push_back(i);
            tmp.push_back(j);
            ord.push_back(tmp);
        }
    }

    // for(auto it : ord) cerr<<it<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}