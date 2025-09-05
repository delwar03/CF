#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    int a, b, c, d; cin>>a>>b>>c>>d;
    --a, --b, --c, --d;

    auto isValid = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    vector<vector<int>> dist(n, vector<int>(m, INF));
    deque<pii> dq;
    dist[a][b] = 0;
    dq.push_front({a, b});

    while(sz(dq)) {
        auto [x, y] = dq.front(); dq.pop_front();
        for(auto [dx, dy] : dir) {
            for(int k = 1; k <= 2; k++) {
                int nx = x + dx * k, ny = y + dy * k;
                if(!isValid(nx, ny)) continue;
                if(k == 1 && v[nx][ny] == '.') {
                    if(dist[x][y] < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y];
                        dq.push_front({nx, ny});
                    }
                } else {
                    if(dist[x][y] + 1 < dist[nx][ny]) {
                        dist[nx][ny] = 1 + dist[x][y];
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
    }

    cout<<dist[c][d]<<endl;
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