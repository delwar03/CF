#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    string a, b; cin>>a>>b;
    int n = a.size(), m = b.size();
    int cnt1 = count(b.begin(), b.begin() + m, '1');
    int cnt2 = count(a.begin(), a.begin() + m, '1');

    int ans = (cnt1 % 2 == cnt2 % 2);

    for(int i = m; i < n; i++) {
        cnt2 -= a[i - m] == '1';
        cnt2 += a[i] == '1';
        ans += (cnt1 % 2 == cnt2 % 2);
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/