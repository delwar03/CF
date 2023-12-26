#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    if(k > 30) {cout<<"0\n"; return;}

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        int a = i, b = n;
        bool hobe = true;
        for(int j = 1; j <= k - 2; j++) {
            int tmp = b - a;
            b = a;
            a = tmp;
            if(a <= b && a >= 0) continue;
            else {hobe = false; break;}
        }
        if(hobe) ans++;
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