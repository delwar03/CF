#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<vector<int>> grid(n + 1, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        grid[x][y] = 1;
    }

    int ans = 0;

    for(int i = 0; i <= n; i++) {
        if(grid[i][0] && grid[i][1]) {
            ans += n - 2;
        }
        for(int j = 0; j <= 1; j++) {
            if(i - 1 >= 0 && i + 1 <= n && grid[i][j] && grid[i - 1][!j] && grid[i + 1][!j]) {
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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