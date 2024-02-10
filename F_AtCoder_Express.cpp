#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int f(int a, int b) {
    int ans = 1, cnt = 0;
    while(a) {
        cnt++;
        a /= 10;
    }
    ans = max(ans, cnt);
    cnt = 0;
    while(b) {
        cnt++;
        b /= 10;
    }
    ans = max(ans, cnt);
    return ans;
}

void solve() {
    int n; cin>>n;
    vector<int> t(n), v(n);
    for(auto &x : t) cin>>x;
    for(auto &x : v) cin>>x;
    t.push_back(0);
    v.push_back(0);
    int prvVel = 0, remTime = 0;
    double ans = 0;
    for(int i = 0; i < n; i++) {
        int effTime = t[i] - abs(v[i + 1] - v[i]);
        if(effTime < 0) continue;
        int dst = min(v[i], effTime);
        ans += dst * dst / 2.0;
        if(effTime >= v[i]) {ans += 1.0 * (effTime - v[i]) * v[i]; prvVel = v[i];}
        else prvVel = effTime;
        ans += (prvVel + v[i + 1]) * (t[i] - remTime) / 2.0;
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