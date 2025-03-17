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
    int arr[5]; cin>>arr[0]>>arr[1]>>arr[3]>>arr[4];
    int mx = 0, ct = 0;
    arr[2] = arr[0] + arr[1];
    for(int i = 2; i < 5; i++) ct += (arr[i] == arr[i - 1] + arr[i - 2]);
    mx = max(mx, ct);

    ct = 0;
    arr[2] = arr[3] - arr[1];
    for(int i = 2; i < 5; i++) ct += (arr[i] == arr[i - 1] + arr[i - 2]);
    mx = max(mx, ct);

    ct = 0;
    arr[2] = arr[4] - arr[3];
    for(int i = 2; i < 5; i++) ct += (arr[i] == arr[i - 1] + arr[i - 2]);
    mx = max(mx, ct);

    cout<<mx<<endl;
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