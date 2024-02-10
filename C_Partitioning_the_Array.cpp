#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> v;
    v.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i) v.push_back(n / i);
        }
    }
    if(n != 1) v.push_back(n);
    return v;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> factors = getFactors(n);
    // for(auto it : factors) cout<<it<<" "; cout<<endl;
    int ans = 0;
    for(auto it : factors) {
        int g = 0;
        for(int j = 0; j + it < n; j++) {
            g = __gcd(g, abs(v[j] - v[j + it]));
        }
        if(g != 1) ans++;
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