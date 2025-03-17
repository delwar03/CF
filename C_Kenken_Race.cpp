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

int dp[N];

void solve() {
    int n, a, b, c, d; cin>>n>>a>>b>>c>>d;
    string dir; cin>>dir;
    --a; --b; --c; --d;

    int f = 0;

    function<int(int, int)> magic = [&] (int s, int t) {
        if(s == t) return 1LL;
        int &ans = dp[s];
        if(~ans) return ans;
        ans = 0;
        if((s + 1 <= t && dir[s + 1] != '#'))
            ans |= magic(s + 1, t);
        if(s + 2 <= t && dir[s + 2] != '#')
            ans |= magic(s + 2, t);

        return ans;
    };

    memset(dp, -1, sizeof dp);
    if(!magic(b, d)) {cout<<"No"<<endl; return; }
    
    if(c < d) {
        memset(dp, -1, sizeof dp);
        cout<<(magic(a, c) ? "Yes" : "No")<<endl;
    } else {
        f = 1;
        memset(dp, -1, sizeof dp);
        if(!magic(a, c)) {cout<<"No"<<endl; return; }
        for(int i = max(0LL, b - 1); i + 2 <= min(n - 1, d + 1); i++) {
            if(dir[i] == '.' && dir[i + 1] == '.' && dir[i + 2] == '.') {
                cout<<"Yes"<<endl; return;
            }
        }
        cout<<"No"<<endl;
    }
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