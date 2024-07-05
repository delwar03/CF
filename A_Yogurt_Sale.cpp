#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

void solve() {
    int n, a, b; cin>>n>>a>>b;
    int ans = 0;
    if(2 * a < b) ans = n * a;
    else {
        ans = (n / 2) * b;
        ans += (n % 2) * a;
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