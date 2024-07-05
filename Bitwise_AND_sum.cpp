#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int ans = 0;
    for(int bit = 0; bit < 25; bit++) {
        int i = 0, j = n - 1;
        int cnt1 = 1, cnt2 = 1;
        while(i < n && ((v[i] >> bit) & 1)) {
            i++;
            cnt1++;
        }
        while(j >= 0 && ((v[j] >> bit) & 1)) {
            j--;
            cnt2++;
        }
        // cerr<<cnt1<<" "<<cnt2<<endl;
        ans += (i > j ? ((n * (n + 1) / 2) - 1) : (cnt1 * cnt2 - 1)) * (1LL << bit);
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