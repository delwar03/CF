#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) { cin>>a[i]; }
    int ans = 1, cnt = 1, mx = a[1];
    for(int i = 2; i <= n; i++) {
        if(a[i] > mx) {
            if(cnt == mx) ans++;
            mx = a[i];
        }
        cnt++;
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