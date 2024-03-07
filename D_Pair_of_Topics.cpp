#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<int> dif(n);
    
    for(int i = 0; i < n; i++) {
        dif[i] = a[i] - b[i];
    }
    auto sorted = dif;
    sort(sorted.begin(), sorted.end());
    // for(auto it : dif) cout<<it<<" "; cout<<endl;
    // for(auto it : sorted) cout<<it<<" "; cout<<endl;
    int ans = 0;
    for(auto it : dif) {
        int ind = upper_bound(sorted.begin(), sorted.end(), -it) - sorted.begin();
        // if(ind) ind--;
        ind = n - ind;
        // cerr<<ind<<" ";
        if(it > 0) ans += ind - 1;
        else ans += ind;
    }
    cout<<ans / 2<<endl;
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