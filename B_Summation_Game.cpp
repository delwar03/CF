#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k, x; cin>>n>>k>>x;
    int sum = 0;
    vector<int> v(n);
    for(auto &x : v) {cin>>x; sum += x;}
    sort(v.begin(), v.end());
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1] + v[i - 1];
    }
    int ans = -INF;
    for(int i = 0; i <= k; i++) {
        int tmp = - pref[n - i] + 2 * pref[max(0LL, n - x - i)];

        ans = max(ans, tmp);
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