#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) {cin>>x; }
    sort(v.begin(), v.end());
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i - 1];
    while(q--) {
        int x; cin>>x;
        int ind = upper_bound(pref.begin(), pref.end(), x) - pref.begin();
        cout<<ind - 1<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 