#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
    }
    vector<int> factors;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            if(n / i != i) factors.push_back(n / i);
        }
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + v[i - 1];
    }
    // for(auto it : pref) cerr<<it<<" "; cerr<<endl;
    int ans = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
    for(auto it : factors) {
        int mn = INF, mx = -INF;
        for(int i = 1; i <= n / it; i++) {
            int val = pref[i * it] - pref[(i - 1) * it];
            mn = min(mn, val);
            mx = max(mx, val);
        }
        ans = max(ans, mx - mn);
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