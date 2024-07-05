#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e15 + 10;

void solve() {
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int right = x2 - x1;
    int down = y2 - y1;

    cout<<right * down + 1<<endl;
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