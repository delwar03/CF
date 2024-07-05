#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

vector<vector<int>> g[105];
int dp[105][105][30];

int dfs(int a, int b, int cur) {
    int &ans = dp[a][b][cur];

    if(~ans) return ans;

    int res = 0;

    for(auto it : g[a]) {
        int c = it[0], wt = it[1];
        if(wt >= cur && dfs(b, c, wt) == 0) {
            res = 1;
            break;
        }
    }

    return ans = res;
}

void solve() {
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u, v; 
        char wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt - 'a'});
    }

    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout<<(dfs(i, j, 0) == 1 ? "A" : "B");
        }
        cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/