#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int linSum (int x) {
    return x * (x + 1) / 2;
}


void solve() {
    int n, k, q; cin>>n>>k>>q;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] <= q) {
            cnt++;
        } else {
            if(cnt >= k) {
                ans += linSum(cnt - k + 1);
            }
            cnt = 0;
        }
    }
    if(cnt >= k) {
        ans += linSum(cnt - k + 1);
    }
    cout<<ans<<endl;
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