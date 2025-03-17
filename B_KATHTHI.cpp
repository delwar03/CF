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

struct Node {
    int x, y;
    Node() : x(0), y(0) {}
    Node(int a, int b) : x(a), y(b) {}
};

vector<vector<int>> dir = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve() {
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    vector<vector<int>> dp(n, vector<int>(m, INF));

    deque<Node> dq;
    dq.push_back(Node(0, 0));
    dp[0][0] = 0;

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    while(dq.size()) {
        auto cur = dq.front();
        dq.pop_front();

        int i = cur.x, j = cur.y;

        // cerr<<"i: "<<i<<", j: "<<j<<" -> "<<dp[i][j]<<endl;

        for(auto it : dir) {
            int ni = i + it[0], nj = j + it[1];
            if(valid(ni, nj)) {
                if(v[i][j] != v[ni][nj]) {
                    if(dp[ni][nj] > dp[i][j] + 1) {
                        dp[ni][nj] = dp[i][j] + 1;
                        dq.push_back({ni, nj});
                    }
                } else {
                    if(dp[ni][nj] > dp[i][j]) {
                        dp[ni][nj] = dp[i][j];
                        dq.push_front({ni, nj});
                    }
                }
            }
        }
    }

    cout<<dp[n - 1][m - 1]<<endl;
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