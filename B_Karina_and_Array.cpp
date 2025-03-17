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
    int n; cin >>n ;
    int a[n];
    vector < int>pos , neg;
    for (int i=0 ; i<n ;i++) {
        cin >> a[i] ;
        if (a[i] < 0) neg.push_back (a[i]);
        else pos.push_back (a[i]);
    }
    if (neg.size () < 2 && pos.size () < 2){
        cout << a[0] * a[1] <<"\n"; return;
    }
    sort (neg.begin () , neg.end ());
    int ans= 0 ;
    if (neg.size () > 1) {
        ans= abs (neg[0] * neg[1]);
    } 
    sort (pos.begin () , pos.end ());
    if (pos.size () > 1) {
       int se = pos[pos.size () -1 ] *  pos[pos.size () -2 ];
       ans= max (ans ,se);
    }

    cout << ans <<"\n";
    
 
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