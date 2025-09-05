#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

void solve() {
    int n; cin>>n;
    int Ax, Ay, Bx, By; cin>>Ax>>Ay>>Bx>>By;
    --Ax, --Ay, --Bx, --By;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    auto isValid = [&] (int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n && v[x][y] != '#';
    };

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));
    deque<array<int, 3>> dq;
    for(int i = 0; i < 4; i++) {
        dq.push_front({Ax, Ay, i});
        dist[Ax][Ay][i] = 1;
    }

    while(sz(dq)) {
        auto [x, y, d] = dq.front(); dq.pop_front();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!isValid(nx, ny)) continue;
            int f = (d != i);
            if(dist[nx][ny][i] > f + dist[x][y][d]) {
                dist[nx][ny][i] = f + dist[x][y][d];
                (f ? dq.push_back({nx, ny, i}) : dq.push_front({nx, ny, i}));
            }
        }
    }

    int mn = INF;
    for(int i = 0; i < 4; i++) {
        mn = min(mn, dist[Bx][By][i]);
    }
    
    cout<<(mn == INF ? -1 : mn)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}