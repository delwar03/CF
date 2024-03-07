#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;
int n;
vector<string> grid;
int dist[N][N];
vector<vector<int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void solve() {
    cin>>n;
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        grid.push_back(s);
    }
    int s1 = -1, s2 = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'P') {
                if(s1 == -1) s1 = i * n + j;
                s2 = i * n + j;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }
    auto isValid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n && grid[i][j] != '#';
    };

    queue<vector<int>> q;
    q.push({s1, s2});
    dist[s1][s2] = 0;

    while(!q.empty()) {
        int p1 = (q.front())[0];
        int p2 = (q.front())[1];
        q.pop();
        if(p1 == p2) {
            cout<<dist[p1][p2]<<endl;
            return;
        }
        int x1 = p1 / n;
        int y1 = p1 % n;
        int x2 = p2 / n;
        int y2 = p2 % n;
        
        for(int d = 0; d < 4; d++) {
            int n_x1 = x1 + dir[d][0];
            int n_y1 = y1 + dir[d][1];
            int n_x2 = x2 + dir[d][0];
            int n_y2 = y2 + dir[d][1];

            if(!isValid(n_x1, n_y1)) {
                n_x1 = x1;
                n_y1 = y1;
            }
            if(!isValid(n_x2, n_y2)) {
                n_x2 = x2;
                n_y2 = y2;
            }

            int n_p1 = n_x1 * n + n_y1;
            int n_p2 = n_x2 * n + n_y2;

            if(dist[p1][p2] + 1 < dist[n_p1][n_p2]) {
                dist[n_p1][n_p2] = dist[p1][p2] + 1;
                q.push({n_p1, n_p2});
            }
        }
    }

    // for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) cerr<<dist[i][j]<<" \n"[j == n];
    cout<<"-1"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 