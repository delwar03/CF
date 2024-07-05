#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int a, b, c; cin>>a>>b>>c;
    int cnt = 0;
    while(cnt++ <= b) {
        int now = a * 10;
        if(now / b == c) {
            cout<<cnt<<endl;
            return;
        }
        a = now % b;
    }
    cout<<-1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/