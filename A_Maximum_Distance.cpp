#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = 0, y = 0;
        for(int j = i; j < n; j++) {
            if(a[j - i] != b[j]) x++;
            if(b[j - i] != a[j]) y++;
        }
        ans = max(ans, max(x, y));
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