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

vector<int> di;

void solve() {
    int k; cin>>k;
    int tmp = k;
    vector<int> cur;
    for(int i = 0; i < sz(di); i++) {
        int x = di[i];
        while(tmp && tmp >= x) tmp -= x, cur.push_back(500 - i);
    }

    // for(auto x : cur) cerr<<x<<" "; cerr<<endl;

    if(!sz(cur)) {cout<<0<<endl; return; }

    int n = accumulate(cur.begin(), cur.end(), 0LL);
    cout<<n<<endl;

    vector<int> X, Y;

    int p = 1;

    for(int x : cur) {
        for(int i = 0; i < x; i++) X.push_back(p);
        p++;
    }

    p = -1;
    for(int x : cur) {
        for(int i = 0; i < x; i++) Y.push_back(p--);
    }

    for(int i = 0; i < n; i++) cout<<X[i]<<" "<<Y[i]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 500; i > 1; i--) di.push_back((i * (i - 1)) / 2);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}