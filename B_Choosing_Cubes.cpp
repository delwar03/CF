#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    int n, f, k; cin>>n>>f>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    --f;
    int fav = v[f];
    sort(v.rbegin(), v.rend());
    int i = 0, p = 0;
    for(i; i < k; i++) {
        if(v[i] == fav) p = 2;
    }
    if(p == 0) {
        cout<<"NO"<<endl;
        return;
    }
    for(i; i < n; i++) {
        if(v[i] == fav) p = 1;
    }

    if(p == 2) {
        cout<<"YES"<<endl;
    } else {
        cout<<"MAYBE"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/