#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {0, 0}
};

void solve() {
    int n, m, k; cin>>n>>m>>k;
    int si, sj; cin>>si>>sj; 
    --si; --sj;
    vector<vector<int>> v(n, vector<int>(m));
    for(auto &a : v) {
        for(auto &b : a) {
            cin>>b;
        }
    }
    
    vector<vector<int>> prev(n, vector<int>(m, -INF));
    prev[si][sj] = 0;
    int ans = v[si][sj] * k;

    for(int steps = 1; steps <= min(k, n * m); steps++) {
        vector<vector<int>> cur(n, vector<int>(m, -INF));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int d = 0; d < 5; d++) {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    cur[i][j] = max(cur[i][j], v[i][j] + prev[x][y]);
                }
            }
        }
        prev = cur;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, prev[i][j] + v[i][j] * (k - steps));
            }
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/