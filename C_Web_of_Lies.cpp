#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        cnt[min(u, v)]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += (cnt[i] == 0);
    int q; cin>>q;
    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int u, v; cin>>u>>v;
            ans -= (cnt[min(u, v)] == 0);
            cnt[min(u, v)]++;
        } else if(type == 2) {
            int u, v; cin>>u>>v;
            cnt[min(u, v)]--;
            ans += (cnt[min(u, v)] == 0);
        } else {
            cout<<ans<<endl;
        }
    }
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