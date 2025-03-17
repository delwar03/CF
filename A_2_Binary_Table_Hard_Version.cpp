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
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m)), vis(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch; cin>>ch;
            v[i][j] = ch - '0';
        }
    }
    
    vector<array<int, 6>> ans;

    auto f = [&] (vector<pii> one, vector<pii> zero) {
        // cerr<<sz(one)<<" "<<sz(zero)<<endl;

        if(sz(one) == 1) {
            ans.push_back({one[0].F, one[0].S, zero[0].F, zero[0].S, zero[1].F, zero[1].S});
            ans.push_back({one[0].F, one[0].S, zero[0].F, zero[0].S, zero[2].F, zero[2].S});
            ans.push_back({one[0].F, one[0].S, zero[1].F, zero[1].S, zero[2].F, zero[2].S});
        } else if(sz(one) == 3) {
            ans.push_back({one[0].F, one[0].S, one[1].F, one[1].S, one[2].F, one[2].S});
        } else if(sz(one) == 2) {
            ans.push_back({one[0].F, one[0].S, zero[0].F, zero[0].S, zero[1].F, zero[1].S});
            ans.push_back({one[1].F, one[1].S, zero[0].F, zero[0].S, zero[1].F, zero[1].S});
        } else if(sz(one) == 4) {
            ans.push_back({one[1].F, one[1].S, one[2].F, one[2].S, one[3].F, one[3].S});
            ans.push_back({one[0].F, one[0].S, one[1].F, one[1].S, one[2].F, one[2].S});
            ans.push_back({one[0].F, one[0].S, one[2].F, one[2].S, one[3].F, one[3].S});
            ans.push_back({one[0].F, one[0].S, one[1].F, one[1].S, one[3].F, one[3].S});
        }
        for(auto [i, j] : one) v[i][j] = 0;
        for(auto [i, j] : zero) v[i][j] = 0;
    };

    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j]) {
                if(j + 1 < m) {
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                    v[i][j] ^= 1, v[i + 1][j] ^= 1, v[i + 1][j + 1] ^= 1;
                } else {
                    ans.push_back({i, j, i + 1, j, i + 1, j - 1});
                    v[i][j] ^= 1, v[i + 1][j] ^= 1, v[i + 1][j - 1] ^= 1;
                }
            }
        }
    }
    
    for(int j = 0; j < m - 2; j++) {
        if(v[n - 2][j]) {
            ans.push_back({n - 2, j, n - 2, j + 1, n - 1, j + 1});
            v[n - 2][j] ^= 1, v[n - 2][j + 1] ^= 1, v[n - 1][j + 1] ^= 1;
        }
        if(v[n - 1][j]) {
            ans.push_back({n - 1, j, n - 1, j + 1, n - 2, j + 1});
            v[n - 1][j] ^= 1, v[n - 1][j + 1] ^= 1, v[n - 2][j + 1] ^= 1;
        }
    }

    vector<pii> one, zero;
    for(int i : {n - 2, n - 1}) {
        for(int j : {m - 2, m - 1}) {
            if(v[i][j]) {
                one.push_back({i, j});
            } else {
                zero.push_back({i, j});
            }
        }
    }
    f(one, zero);

    cout<<sz(ans)<<endl;
    for(auto it : ans) {
        for(auto i : it) cout<<i + 1<<" "; cout<<endl;
    }
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