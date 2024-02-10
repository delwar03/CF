#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, m;
vector<string> v;
int distFire[205][205], distJane[205][205];

vector<vector<int>> dir = {
    {1, 0}, 
    {-1, 0}, 
    {0, 1}, 
    {0, -1}
}; // DURL

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void reset() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            distFire[i][j] = distJane[i][j] = -1;
        }
    }
    v.clear();
}


void solve() {
    cin>>n>>m;
    reset();
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        v.push_back(s);
    }

    queue<vector<int>> q;
    int xpos_Jane, ypos_Jane;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'F') q.push({i, j, 0}); // {x, y, steps}
            if(v[i][j] == 'J') xpos_Jane = i, ypos_Jane = j;
        }
    }
    
    while(!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int steps = q.front()[2];
        q.pop();

        if(!isValid(x, y) || v[x][y] == '#' || distFire[x][y] != -1) continue;

        distFire[x][y] = steps;
        for(int d = 0; d < 4; d++) {
            int new_x = x + dir[d][0];
            int new_y = y + dir[d][1];
            q.push({new_x, new_y, steps + 1});
        }
    }
    while(!q.empty()) q.pop();

    q.push({xpos_Jane, ypos_Jane, 0}); // {jane_x, jane_y, steps}
    while(!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int steps = q.front()[2];
        q.pop();

        if(!isValid(x, y) || v[x][y] == '#' || distJane[x][y] != -1 || (distFire[x][y] >= 0 && distFire[x][y] <= steps)) continue;

        if(x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            cout<<steps + 1<<endl;
            return;
        }
        distJane[x][y] = steps;
        for(int d = 0; d < 4; d++) {
            int new_x = x + dir[d][0];
            int new_y = y + dir[d][1];
            q.push({new_x, new_y, steps + 1});
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 