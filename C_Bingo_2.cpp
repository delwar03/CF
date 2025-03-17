#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, t; cin>>n>>t;
    vector<int> v(t);
    for(auto &x : v) {cin>>x; --x;}
    vector<vector<int>> grid(n, vector<int>(n));
    vector<int> row(n), col(n);
    int d1 = 0, d2 = 0;
    for(int i = 0; i < t; i++) {
        int r = v[i] / n, c = v[i] % n;
        if(!grid[r][c]) {
            grid[r][c] = 1;
            row[r]++, col[c]++;
            if(r == c) d1++;
            if(r + c == n - 1) d2++;
            if(row[r] == n || col[c] == n || d1 == n || d2 == n) {
                cout<<i + 1<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
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

/*
i/p: 
o/p: 
*/