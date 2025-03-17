#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n; cin>>n;
    vector<string> v(2);
    for(auto &x : v) cin>>x;

    auto valid = [&] (int i, int j) {
        if((j + 1 < n && v[i][j + 1] == 'x') || (j - 1 >= 0 && v[i][j - 1] == 'x')) return false;
        if((i + 1 < 2 && j - 1 >= 0 && j + 1 < n) && (v[i + 1][j - 1] == 'x' && v[i + 1][j + 1] == 'x' && v[i + 1][j] == '.')) return true;
        if((i - 1 >= 0 && j - 1 >= 0 && j + 1 < n) && (v[i - 1][j - 1] == 'x' && v[i - 1][j + 1] == 'x' && v[i - 1][j] == '.')) return true;
        return false;
    };

    int ans = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            if(valid(i, j)) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
