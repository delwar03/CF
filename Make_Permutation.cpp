#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int mn = INF;
    for(auto &x : v) {cin>>x; mn = x < mn ? x : mn;}
    vector<int> p(n);
    for(int i = 0; i < n; i++) p[i] = i + 1;
    sort(v.begin(), v.end());
    int ind = n;
    // for(auto it : v) cerr<<it<<" "; cerr<<endl;
    // for(auto it : p) cerr<<it<<" "; cerr<<endl;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] > p[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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