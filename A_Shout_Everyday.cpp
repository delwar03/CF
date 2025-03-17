#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, b, c; cin>>a>>b>>c;
    int f = 1;
    if(b > c) {
        swap(b, c);
        f = 0;
    }
    vector<int> vis(24, 0);
    for(int i = b; i <= c; i++) vis[i] = 1;

    if(f) {
        cout<<(!vis[a] ? "Yes" : "No")<<endl;
    } else {
        cout<<(vis[a] ? "Yes" : "No")<<endl;
    }
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