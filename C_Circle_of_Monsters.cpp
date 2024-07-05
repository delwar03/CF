#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i]>>b[i];

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += max(0LL, a[i] - b[(i - 1 + n) % n]);
    }

    int ans = INF;

    for(int i = 0; i < n; i++) {
        int cur = sum + a[i];
        cur -= max(0LL, a[i] - b[(i - 1 + n) % n]);
        ans = min(ans, cur);
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