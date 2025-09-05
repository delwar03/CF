#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int h1, t1, h2, t2; char ch; cin>>h1>>ch>>t1>>h2>>ch>>t2;
    // cerr<<h1<<" "<<t1<<" "<<h2<<" "<<t2<<endl;
    int dif = (h2 - h1) * 60 + (t2 - t1);
    dif /= 2;
    int dh = dif / 60, dm = dif % 60;
    h1 += dh;
    t1 += dm;
    if(t1 >= 60) t1 -= 60, h1++;

    string a = to_string(h1), b = to_string(t1);
    if(sz(a) == 1) a = "0" + a;
    if(sz(b) == 1) b = "0" + b;

    cout<<a<<":"<<b<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}