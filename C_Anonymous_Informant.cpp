#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    bool hobe = true;
    vector<int> v(n + 1), id;
    for(int i = 1; i <= n; i++) {cin>>v[i]; if(v[i] > n) {hobe = false; id.push_back(i);} }
    if(hobe) {cout<<"Yes\n"; return; }
    
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