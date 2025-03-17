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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<char> ord = {'1', '5', '4', '3'};

void solve() {
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    auto chk = [&] (int i, int j) {
        string s = "";
        for(int j = i; j < m - i; j++) {
            s.push_back(v[i][j]);
        }

        for(int j = i + 1; j < n - i; j++) {
            s.push_back(v[j][m - i - 1]);
        }

        for(int j = m - i - 1 - 1; j >= i; j--) {
            s.push_back(v[n - i - 1][j]);
        }

        for(int j = n - i - 1 - 1; j > i; j--) {
            s.push_back(v[j][i]);
        }
    
        s += s;

        int cnt = 0;
        for(int i = 0; i < (int) s.size() / 2; i++) {
            cnt += (s.substr(i, 4) == "1543");
        }

        return cnt;
    };

    int ans = 0;

    for(int i = 0; i < min(n, m) / 2; i++) {
        // (i, i)
        ans += chk(i, i);
    }
    cout<<ans<<endl;
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

/*
i/p: 
o/p: 
*/