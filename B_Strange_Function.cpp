#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
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

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int n; cin>>n;
    int ans = (((n + 1) / 2) * 2) % M;
    ans = (ans + (n / 2) * 3) % M;
    int p = 1 * 2 * 3, ind = 4;
    while(p <= n) {
        ans = (ans + n / p) % M;
        p = lcm(p, ind++);
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