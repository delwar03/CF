#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    int ans = 0;
    vector<int> x_cord, y_cord;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        x_cord.push_back(x);
        y_cord.push_back(y);
    }
    vector<int> pref_x(n + 1, 0), pref_y(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        pref_x[i] = pref_x[i - 1] + x_cord[i - 1];
        pref_y[i] = pref_y[i - 1] + y_cord[i - 1];
    }

    for(int i = 0; i < n; i++) {
        ans += x_cord[i] * x_cord[i];
        ans += y_cord[i] * y_cord[i];
    }
    ans *= (n - 1);

    // for(auto it : pref_x) cerr<<it<<" "; cerr<<endl;
    // for(auto it : pref_y) cerr<<it<<" "; cerr<<endl;

    for(int i = 0; i < n - 1; i++) {
        ans -= 2 * (x_cord[i] * (pref_x[n] - pref_x[i + 1]));
        ans -= 2 * (y_cord[i] * (pref_y[n] - pref_y[i + 1]));
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
