#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
}; // DURL

void solve() {
    int n; cin>>n;
    vector<string> grid(2);
    for(auto &x : grid) cin>>x;
    vector<vector<int>> vis(2, vector<int>(n, 0));
    queue<vector<int>> q;
    vis[0][0] = 1;
    q.push({0, 0});

    auto isValid = [&] (int i, int j) {
        return i >= 0 && i < 2 && j >= 0 && j < n;
    };

    while(q.size()) {
        int r = q.front()[0];
        int c = q.front()[1];
        q.pop();
        for(int d = 0; d < 4; d++) {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if(isValid(nr, nc)) {
                if(grid[nr][nc] == '>') nc++;
                else nc--;
                if(!vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    // for(int i = 0; i < 2; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<(vis[1][n - 1] ? "YES" : "NO")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 