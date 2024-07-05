#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin>>l[i]>>r[i];

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += max(l[i], r[i]);
    }

    cout<<n + ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/