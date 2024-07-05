#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n, k; cin>>n>>k;
    int ans = 0;
    if(n & 1) {
        k += (k - 1) / (n / 2);
        ans = k % n;
    } else {
        ans = k % n;
    }
    cout<<(ans == 0 ? n : ans)<<endl;
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