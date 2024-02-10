#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;
vector<string> v;
int vis[N][N];

int n, m, ans = 0;
vector<vector<int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
}; // DURL

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
    if(!isValid(i, j)) return;
    if(vis[i][j]) return;
    if(v[i][j] == '#') return;
    vis[i][j] = 1;

    for(int d = 0; d < 4; d++) {
        int nx = i + dir[d][0];
        int ny = j + dir[d][1];
        dfs(nx, ny);
    }
    ans++;
}


void solve() {
    cin>>m>>n;
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        v.push_back(s);
    }
    // for(auto it : v) cout<<it<<endl;
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    dfs(x, y);
    cout<<ans<<endl;
    ans = 0;
    memset(vis, 0, sizeof vis);
    v.clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 