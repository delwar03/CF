#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e2 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, x; cin>>n>>x;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.rbegin(), v.rend());
    int ans = 0;
    vector<int> tmp;
    for(int i = 0; i < n; i++) {
        tmp.push_back(v[i]);
        if(tmp.back() * tmp.size() >= x) {
            ans++;
            tmp.clear();
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 