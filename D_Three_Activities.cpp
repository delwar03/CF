#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n), c(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    for(auto &x : c) cin>>x;

    multiset<vector<int>> y, z;
    for(int i = 0; i < n; i++) {
        y.insert({b[i], i});
    }
    for(int i = 0; i < n; i++) {
        z.insert({c[i], i});
    }
    int ans = 0LL;

    for(int i = 0; i < n; i++) {
        y.erase({b[i], i});
        z.erase({c[i], i});

        if((*y.rbegin())[1] == (*z.rbegin())[1]) {
            ans = max({ans, a[i] + (*--y.end())[0] + (*--(--z.end()))[0], a[i] + (*--z.end())[0] + (*--(--y.end()))[0]});
        } else {
            ans = max({ans, a[i] + (*--y.end())[0] + (*--z.end())[0]});
        }

        y.insert({b[i], i});
        z.insert({c[i], i});
    }
    cout<<ans<<endl;
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