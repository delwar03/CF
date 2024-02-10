#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> inv(N);

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin>>n;
    vector<int> ans(n + 1), vis(n + 1);
    int val = (1LL << 30) - 1;
    for(int i = n; i >= 0; i--) {
        while((val ^ i) > n || vis[val ^ i]) val >>= 1;
        ans[i] = val ^ i;
        vis[val ^ i] = 1;
    }
    int res = 0;
    for(int i = 0; i <= n; i++) res += ans[i] ^ i;
    cout<<res<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
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