#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());
    vector<int> pf(n + 1);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] + v[i];
    }
    
    // for(auto it : pf) cerr<<it<<" "; cerr<<endl;

    bool hobe = false;

    for(int i = 1; i <= n; i++) {
        if(pf[i] >= k) {
            hobe = true;
        }
    }
    if(hobe) {
        cout<<"Yes"<<endl;
        for(auto it : v) cout<<it<<" "; cout<<endl;
    } else {
        cout<<"No"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/