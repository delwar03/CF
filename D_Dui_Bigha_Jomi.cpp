#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
double PI = acos(-1.0);
double eps = 1e-5;

void solve() {
    vector<vector<int>> pos1, pos2;
    for(int i = 0; i < 4; i++) {
        int x, y; cin>>x>>y;
        pos1.push_back({x, y});
    }
    for(int i = 0; i < 4; i++) {
        int x, y; cin>>x>>y;
        pos2.push_back({x, y});
    }
    int x1, y1, x2, y2;
    for(int i = 1; i < 4; i++) {
        if(pos1[0][0] != pos1[i][0] && pos1[0][1] != pos1[i][1]) {
            x1 = (pos1[0][0] + pos1[i][0]) / 2;
            y1 = (pos1[0][1] + pos1[i][1]) / 2;
        }
    }
    for(int i = 1; i < 4; i++) {
        if(pos2[0][0] != pos2[i][0] && pos2[0][1] != pos2[i][1]) {
            x2 = (pos2[0][0] + pos2[i][0]) / 2;
            y2 = (pos2[0][1] + pos2[i][1]) / 2;
        }
    }
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 