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
const int N = 110;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,k,d ;
int a[N], dp[N][N][N];
int f (int ind , int cnt , int md) {
    if (ind==n) {
        if (cnt != k) return -INF;
        else {
            if (md==0) return 0;
            else return -INF;
        }
    }
    int &ans= dp[ind][cnt][md];
    if (~ans) return ans;
    ans=-INF;
    ans = max (ans ,f (ind + 1 , cnt , md));
    if(cnt + 1 <= k)
    ans = max (ans ,a[ind] + f (ind +1 , cnt+1 , (a[ind]+md ) % d) );
    return ans;
}

void solve() {
    cin >>n>>k>>d;
    for (int i=0 ;i<n ;i++) cin >> a[i];
    memset (dp ,-1, sizeof dp);
    int ans = f (0,0,0);
    cout << (ans < 0 ? -1 : ans) <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;// cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}