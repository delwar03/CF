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
    vector<int> freq(30);
    for(auto ch : s) freq[ch - 'A'] += 1;

    vector<int> dp(50, -1);

    function<int(int)> f = [&] (int i) {
        if(!i) return 0LL;
        int &ans = dp[i];
        if(~ans) return ans;
        ans = 0;
        vector<bool> F(50);
        if(i - 1 > 0) F[f(i - 1)] = 1;
        if(i - 2 > 0) F[f(i - 2)] = 1;
        F[f(0)] = 1;
        while(F[ans]) ans++;
        return ans;
    };

    int xr = 0;
    for(int i = 0; i < 26; i++) xr ^= f(freq[i]);

    cout<<(xr ? "Alice" : "Bob")<<endl;
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