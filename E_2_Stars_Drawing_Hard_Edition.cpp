#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>grid[i][j];
        }
    }

    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    auto valid = [&] (int i, int j) {
        return i >= 1 && i <= n && j >= 1 && j <= m && grid[i][j] == '*';
    };

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(grid[i][j] == '*') {
                int len = 1;
                for(; ; len++) {
                    int f = true;
                    for(int d = 0; d < 4; d++) {
                        if(!valid(i + len * dir[d][0], j + len * dir[d][1])) {
                            f = false;
                            break;
                        }
                    }
                    if(!f) break;
                    for(int d = 0; d < 4; d++) {
                        vis[i + len * dir[d][0]][j + len * dir[d][1]] = 1;
                    }
                }
                if(len > 1) {
                    ans++;
                    cnt[i][j] = len - 1;
                    vis[i][j] = 1;
                }
            }
        }
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(grid[i][j] == '*' && !vis[i][j]) {
                cout<<-1<<endl;
                return;
            }
        }
    }

    cout<<ans<<endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(cnt[i][j]) {
                cout<<i<<" "<<j<<" "<<cnt[i][j]<<endl;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
