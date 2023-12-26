#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

bool isPossible(int a, int b, int c,  int d) {
    int x = (c + b - 1) / b; // [c / b]
    int y = (a + d - 1) / d; // [a / d]
    return x <= y;
}

void solve() {
    int hc, dc, hm, dm, k, w, a; cin>>hc>>dc>>hm>>dm>>k>>w>>a;
    for(int i = 0; i <= k; i++) {
        if(isPossible(hc + i * a, dc + (k - i) * w, hm, dm)) {cout<<"YES\n"; return;}
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