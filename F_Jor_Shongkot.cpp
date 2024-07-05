#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
double PI = acos(-1.0);
double eps = 1e-5;

void solve() {
    int n; cin>>n;
    int sm = 0;
    vector<int> v(n);
    for(auto &x : v) {cin>>x; sm += x; }

    int tot = n * (n + 1) / 2;
    int x = tot ^ sm;

    cerr<<x<<endl;

    for(auto it : v) cerr<<(it ^ x)<<" "; cerr<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 