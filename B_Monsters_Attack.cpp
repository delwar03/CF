#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n), x(n);
    for(auto &e : a) cin>>e;
    for(auto &e : x) cin>>e;

    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({abs(x[i]), a[i]});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(auto it : v) {
        cnt += it[1];
        if(cnt > it[0] * k) {
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
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 