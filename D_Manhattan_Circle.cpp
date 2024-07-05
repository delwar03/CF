#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    vector<int> X, Y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '#') {
                X.push_back(i + 1);
                Y.push_back(j + 1);
            }
        }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int sz = X.size();

    cout<<X[sz / 2]<<" "<<Y[sz / 2]<<endl;
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