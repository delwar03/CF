#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

void solve() {
    int n, f, a, b; cin>>n>>f>>a>>b;
    vector<int> v;
    v.push_back(0);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        f -= min(b, (x - v.back()) * a);
        v.push_back(x);
    }
    if(f > 0) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 