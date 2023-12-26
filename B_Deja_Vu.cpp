#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> v(n), q(31);
    for(auto &x : v) cin>>x;
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        if(!q[x]) {
            q[x] = 1;
            int val = 1LL << x;
            for(int j = 0; j < n; j++) {
                if(v[j] % val == 0) v[j] += val / 2;
            }
        }
    }
    for(auto &x : v) cout<<x<<" "; cout<<endl;
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