#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    char grid[8][8];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin>>grid[i][j];
        }
    }

    for(int i = 0; i < 8; i++) {
        int cnt = 0;
        for(int j = 0; j < 8; j++) {
            if(grid[i][j] == 'R') {
                cnt++;
            }
        }
        if(cnt == 8) {
            cout<<'R'<<endl;
            return;
        }
    }
    cout<<"B"<<endl;
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