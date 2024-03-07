#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        v[i] += v[i - 1];
    }
    
    int q; cin>>q;
    while(q--) {
        int l, u; cin>>l>>u;
        u += v[l - 1];
        auto it = lower_bound(v.begin(), v.end(), u) - v.begin();
        int r = it;
        if(r > n) cout<<n<<" ";
        else if(r <= l) cout<<l<<" ";
        else {
            if(abs(v[r] - u) <= abs(v[r - 1] - u)) cout<<r<<" ";
            else cout<<r - 1<<" ";
        }
    }
    cout<<endl;
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