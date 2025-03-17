#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> dir = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve() {
    int n, m, y; cin>>n>>m>>y;
    vector<vector<int>> v(n, vector<int>(m));
    for(auto &x : v)
        for(auto &y : x)
            cin>>y;

    map<int, vector<pair<int, int>>> mp;

    for(int i = 0; i < n; i++) {
        mp[v[i][0]].push_back({i, 0});
        mp[v[i][m - 1]].push_back({i, m - 1});
    }
    for(int j = 0; j < m; j++) {
        mp[v[0][j]].push_back({0, j});
        mp[v[n - 1][j]].push_back({n - 1, j});
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int alive = n * m, cur = 1;

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j];
    };

    function<void(int, int)> dfs = [&] (int i, int j) {
        if(vis[i][j]) return;
        alive--;
        vis[i][j] = 1;
        for(int d = 0; d < 4; d++) {
            int nx = i + dir[d][0], ny = j + dir[d][1];
            if(valid(nx, ny)) {
                if(v[nx][ny] <= cur) {
                    dfs(nx, ny);
                } else {
                    mp[v[nx][ny]].push_back({nx, ny});
                }
            }
        }
    };

    for(int i = 0; i < y; i++) {
        if(mp.count(cur)) {
            for(auto it : mp[cur])
                dfs(it.ff, it.ss);
            mp.erase(cur);
        }
        cout<<alive<<endl;
        cur++;
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