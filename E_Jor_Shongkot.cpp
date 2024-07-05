#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n; 
    vector<int> v(n); 
    int x = 0; 
    for(int i = 1; i <= n; i++) x ^= i;

    for(auto &it : v) {cin>>it; x ^= it;} 

    for(int i = 0; i < n; i++) v[i] ^= x; 

    sort(v.begin(), v.end()); 
    for(int i = 0; i < n; i++) {
        if(v[i] != i + 1) {
            cout<<"NO"; return;
        }
    }
    cout<<"YES";
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