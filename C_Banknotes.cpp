#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        x = binPow(10, x);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cnt = k + 1;
        if(i < n - 1)
            cnt = min(cnt, v[i + 1] / v[i] - 1);
        ans += cnt * v[i];
        k -= cnt;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 