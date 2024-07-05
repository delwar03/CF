#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> ind(1005, 0);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        ind[x] = i;
    }

    int mx = -1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(__gcd(i, j) == 1) {
                if(ind[i] && ind[j]) {
                    mx = max(mx, ind[i] + ind[j]);
                }
            }
        }
    }
    cout<<mx<<endl;
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