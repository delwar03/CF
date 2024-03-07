#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> dir = {
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
}; // DURL

bool isValid(int i, int j) {
    return i >= 0 && i < 7 && j >= 0 && j < 7;
}

void solve() {
    vector<string> grid;
    for(int i = 0; i < 7; i++) {
        string s; cin>>s;
        grid.push_back(s);
    }
    
    int ans = 0;
    while(1) {
        int val[7][7];
        memset(val, 0, sizeof val);
        for(int i = 0; i < 7; i++) {
            for(int j = 0; j < 7; j++) {
                if(grid[i][j] == 'B') {
                    bool hobe = true;
                    for(int d = 0; d < 4; d++) {
                        int nrow = i + dir[d][0];
                        int ncol = j + dir[d][1];
                        if(isValid(nrow, ncol)) {
                            // cout<<nrow<<" "<<ncol<<endl;
                            if(grid[nrow][ncol] != 'B') {
                                hobe = false;
                            }
                        } else {
                            hobe = false;
                        }
                    }
                    if(hobe) {
                        for(int d =  0; d < 4; d++) {
                            int nrow = i + dir[d][0];
                            int ncol = j + dir[d][1];
                            // cout<<nrow<<" "<<ncol<<endl;
                            val[nrow][ncol]++;
                        }
                    }
                }
            }
        }
        // cout<<"hello"<<endl;
        int mx = -1;
        for(int i = 0; i < 7; i++) {
            for(int j = 0; j < 7; j++) {
                if(val[i][j] > mx) {
                    mx = val[i][j];
                }
            }
        }
        // cout<<"mx :"<<mx<<endl;
        if(mx <= 0) {
            cout<<ans<<endl;
            return;
        }
        ans++;
        int f = 0;
        for(int i = 0; i < 7; i++) {
            for(int j = 0; j < 7; j++) {
                if(val[i][j] == mx) {
                    grid[i][j] = 'W';
                    f = 1;
                    break;
                }
            }
            if(f) break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 