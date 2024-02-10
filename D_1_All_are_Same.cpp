#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int mn = INF, sum = 0;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    mn = INF, sum = 0;

    for(auto &x : v) {
        cin>>x;
        mn = min(mn, x);
    }
    
    bool allEqual = true;
    for(int i = 1; i < n; i++) {
        if(v[i] != v[i - 1]) {
            allEqual = false;
            break;
        }
    }
    if(allEqual) {
        cout<<"-1\n";
        return;
    }

    int ans = 0;
    for(auto it : v) {
        ans = __gcd(ans, it - mn);
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