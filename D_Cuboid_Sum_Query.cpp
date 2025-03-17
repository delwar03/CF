#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<vector<int>>> v(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    vector<vector<vector<int>>> pf(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                cin>>v[i][j][k];
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                pf[i][j][k] = v[i][j][k] + pf[i - 1][j][k] + pf[i][j - 1][k] + pf[i][j][k - 1]
                                         - pf[i - 1][j - 1][k] - pf[i - 1][j][k - 1] - pf[i][j - 1][k - 1]
                                         + pf[i - 1][j - 1][k - 1];
            }
        }
    }

    auto query = [&] (int Lx, int Rx, int Ly, int Ry, int Lz, int Rz) {
        return pf[Rx][Ry][Rz]
            - pf[Lx-1][Ry][Rz] - pf[Rx][Ly-1][Rz] - pf[Rx][Ry][Lz-1]
            + pf[Lx-1][Ly-1][Rz] + pf[Lx-1][Ry][Lz-1] + pf[Rx][Ly-1][Lz-1]
            - pf[Lx-1][Ly-1][Lz-1];
    };

    int q; cin>>q;
    while(q--) {
        int Lx, Rx, Ly, Ry, Lz, Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        cout << query(Lx, Rx, Ly, Ry, Lz, Rz) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/