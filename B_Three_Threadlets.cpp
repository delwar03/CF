#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, b, c; cin>>a>>b>>c;
    int sum = a + b + c;
    for(int i = 3; i < 7; i++) {
        if(sum % i) continue;
        int d = sum / i;
        if(a % d == 0 && b % d == 0 && c % d == 0) {cout<<"YES\n"; return;}
    }
    cout<<"NO\n";
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