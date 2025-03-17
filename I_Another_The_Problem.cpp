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
    int arr[3], brr[3];
    cin>>arr[0]>>brr[0];
    cin>>arr[1]>>brr[1];
    cin>>arr[2]>>brr[2];
    int tw = 0, fiv = 0;

    for(int i = 0; i < 3; i++) {
        if(arr[i] == 0) {cout<<1<<endl; return; }
        int tmp = arr[i], ct = 0;
        while(tmp % 2 == 0) tmp /= 2, ct++;
        tw += ct * brr[i];

        tmp = arr[i], ct = 0;
        while(tmp % 5 == 0) tmp /= 5, ct++;
        fiv += ct * brr[i];
    }

    cout<<min(tw, fiv)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}