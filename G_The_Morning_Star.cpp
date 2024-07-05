#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e9 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    int ans = 0;
    map<int, int> row, col, mainDiag, subDiag;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        ans += row[x];
        ans += col[y];
        ans += mainDiag[x + y];
        ans += subDiag[x - y];

        row[x]++;
        col[y]++;
        mainDiag[x + y]++;
        subDiag[x - y]++;
    }
    cout<<2 * ans<<endl;
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