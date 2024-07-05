#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void solve() {
    int n, m; cin>>n>>m;
    int grid[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>grid[i][j];
        }
    }

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int mx = -1;
            for(int d = 0; d < 4; d++) {
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                if(valid(ni, nj)) {
                    mx = max(mx, grid[ni][nj]);
                }
            }
            if(grid[i][j] > mx) {
                grid[i][j] = mx;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<grid[i][j]<<" \n"[j == m - 1];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/