#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

void solve() {
    int h, w, n; cin>>h>>w>>n;
    string t; cin>>t;
    vector<string> grid;
    for(int i = 0; i < h; i++) {
        string s; cin>>s;
        grid.push_back(s);
    }
    vector<vector<int>> position(h, vector<int>(w, 0));

    auto DFS = [&](int i, int j) {

        vector<int> res = {i, j};

        for(int k = 0; k < n; k++) {
            if(t[k] == 'D') {
                i++;
            } else if(t[k] == 'U') {
                i--;
            } else if(t[k] == 'R') {
                j++;
            } else {
                j--;
            }
            if(i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != '.') {
                res.clear();
                break;
            }
        }
        if(res.size()) res = {i, j};
        return res;
    };

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == '.') {
                auto vec = DFS(i, j);
                if(vec.size()) {
                    position[vec[0]][vec[1]] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(position[i][j] == 1) {
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

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 