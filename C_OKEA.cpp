#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int l, r; cin>>l>>r;
    int tot = l * r;
    int even = tot / 2;
    int req_even = r * (l / 2);
    if(even != req_even) {cout<<"NO\n"; return; }

    cout<<"YES\n";
    int x =  1, y = 2;
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= r; j++) {
            if(i & 1) {cout<<x<<" "; x += 2; }
            else {cout<<y<<" "; y += 2; }
        }
        cout<<endl;
    }
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