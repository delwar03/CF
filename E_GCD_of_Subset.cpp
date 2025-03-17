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
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin >>n >> k;
    map < int ,int> mp;
    int a[n];
    for (int i=0 ;i<n ;i++) {
        cin >> a[i]; mp[a[i]]++;
    }
    int mx = *max_element (a ,a+n);
    //cerr << mx ;
    vector < int > ans (mx+1 ,1);
    for (int i=1 ; i <= mx;i++) {
        int cnt=0;
        for (int j = i ; j <= mx ;j += i) cnt += mp[j];
        if (cnt >= k) {
            for (int j=i ; j <= mx ; j += i) {
                ans[j] = i;
            }
        }
    }
    for (int i=0 ; i<n ;i++) {
        int tmp= a[i];
        cout << ans [tmp] <<"\n";
    }   
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