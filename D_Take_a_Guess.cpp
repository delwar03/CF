#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
// #define endl '\n'
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
    int n, k; cin>>n>>k;

    auto ask = [&] (int i, int j, int f) {
        cout<<(f ? "or " : "and ")<<i + 1<<" "<<j + 1<<endl;
        int x; cin>>x;
        return x;
    };

    vector<int> sm(n);
    for(int i = 0; i + 1 < n; i++) {
        sm[i] = ask(i, i + 1, 0) + ask(i, i + 1, 1);
    }

    int x = sm[0], y = ask(0, 2, 0) + ask(0, 2, 1);

    int a = (x + y - sm[1]) / 2;

    vector<int> v(n);
    v[0] = a;
    for(int i = 1; i < n; i++) {
        v[i] = sm[i - 1] - v[i - 1];
    }

    sort(v.begin(), v.end());
    
    cout<<"finish "<<v[k - 1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // for(int i = 0; i <= 100; i++) {
    //     for(int j = 0; j <= 100; j++) {
    //         cerr<<(i | j) + (i & j)<<" "<<i + j<<endl;
    //     }
    // }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}