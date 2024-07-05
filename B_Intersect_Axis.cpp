#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
double PI = acos(-1.0);
double eps = 1e-5;

void solve() {
    int n; cin>>n;
    int fr = 0, se = 0, th = 0, fo = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        if(x < 0) {
            if(y < 0) {
                ans += fr;
                th++;
            } else {
                ans += fo;
                se++;
            }
        } else {
            if(y < 0) {
                ans += se;
                fo++;
            } else {
                ans += th;
                fr++;
            }
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 