#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int x, y, k; cin>>x>>y>>k;
    if(k & 1) {
        cout<<x<<" "<<y<<endl;
        k--;
    }

    for(int i = 1; i <= k / 2; i++) cout<<x + i<<" "<<y + i<<endl;
    for(int i = 1; i <= k / 2; i++) cout<<x - i<<" "<<y - i<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/