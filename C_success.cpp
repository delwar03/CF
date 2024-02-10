#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

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
    vector<int> v(n + 1), ans(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    for(int i = 1; i <= n; i++) v[i] += v[i - 1];
    for(int i = n; i >= 1; i--) {
        for(int j = i - 1; j >= 0; j--) {
            if(v[i] - v[j] <= n) ans[v[i] - v[j]]++;
            else break;
        }
    }
    for(int i = 1; i <= n; i++) cout<<ans[i]<<" "; cout<<endl;
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