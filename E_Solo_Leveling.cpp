#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, m; cin>>a>>m;
    int g = __gcd(a, m);
    m /= g;
    int ans = m;
    for(int i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            ans -= ans / i;
            while(m % i == 0) m /= i;
        }
    }
    if(m > 1) ans -= ans / m;
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