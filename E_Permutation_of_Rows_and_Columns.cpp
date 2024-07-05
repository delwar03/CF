#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    int n, m; cin>>n>>m;
    map<int, int> row, col;
    int a[n][m], b[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            row[a[i][j]] = i;
            col[a[i][j]] = j;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>b[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            if(row[b[i][j]] != row[b[i][j + 1]]) {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            if(col[b[i][j]] != col[b[i + 1][j]]) {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
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