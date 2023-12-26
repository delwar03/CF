#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, a, b; cin>>n>>a>>b;
    vector<int> pref(10005, 0), v(n);
    for(auto &x : v) {
        cin>>x;
        pref[x]++;
    }
    for(int i = 1; i < 10005; i++) pref[i] += pref[i - 1];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(0LL, pref[max(0LL, b - v[i])] - pref[max(v[i], a - v[i] - 1)]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 2
     5
     3 6
     1 2 3 4 5
     11
     11 20
     16 11 4 14 7 6 16 9 17 16 8
     
o/p: Case 1: 6
     Case 2: 19
*/ 