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
const int N = 2e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> vals;
vector<vector<int>> mpX(N);
vector<vector<int>> mpY(N);

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>grid[i][j];
            vals.push_back(grid[i][j]);
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto getId = [&] (int x) {
        int ind = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        return ind;
    };

    int mx = 0;

    for(auto &x : grid) for(auto &y : x) 
        y = getId(y), mx = max(mx, y);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mpX[grid[i][j]].push_back(i);
            mpY[grid[i][j]].push_back(j);
        }
    }

    int ans = 0;

    for(int i = 0; i <= mx; i++) {
        auto vecX = mpX[i];
        auto vecY = mpY[i];
        sort(vecX.begin(), vecX.end());
        sort(vecY.begin(), vecY.end());

        int sz = vecX.size();
        int sm = 0, curSm = accumulate(vecX.begin(), vecX.end(), 0LL);
        for(int j = sz - 1; j >= 0; j--) {
            curSm -= vecX[j];
            sm += j * vecX[j];
            sm -= curSm;
        }
        ans += 2 * sm;

        sz = vecY.size();
        sm = 0, curSm = accumulate(vecY.begin(), vecY.end(), 0LL);
        for(int j = sz - 1; j >= 0; j--) {
            curSm -= vecY[j];
            sm += j * vecY[j];
            sm -= curSm;
        }
        ans += 2 * sm;
    }

    cout<<ans<<endl;
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