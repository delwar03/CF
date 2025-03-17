#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.rbegin(), v.rend());

    for(int i = 1; i < n; i += 2) {
        int diff = v[i - 1] - v[i];
        if(diff <= k) {
            v[i] += diff;
            k -= diff;
        } else {
            v[i] += k;
            break;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            ans += v[i];
        } else {
            ans -= v[i];
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
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/