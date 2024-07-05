#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 205;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> q(n), a(n), b(n);
    for(auto &x : q) cin>>x;
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    auto getMin = [&]() {
        int mn1 = INF, mn2 = INF;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) continue;
            int p1 = q[i] / a[i];
            mn1 = min(mn1, p1);
            if(p1 == 0) {
                mn1 = INF;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(b[i] == 0) continue;
            int p2 = q[i] / b[i];
            mn2 = min(mn2, p2);
            if(p2 == 0) {
                mn2 = INF;
                break;
            }
        }

        vector<int> ret;
        ret.push_back(mn1);
        ret.push_back(mn2);
        return ret;
    };
    
    auto tmp = getMin();
    // cout<<tmp[0]<<" "<<tmp[1]<<endl;
    int ans = 0;
    while(tmp[0] != INF && tmp[1] != INF) {

        if(tmp[0] < tmp[1]) {
            for(int i = 0; i < n; i++) {
                q[i] -= b[i];
            }
        } else {
            for(int i = 0; i < n; i++) {
                q[i] -= a[i];
            }
        }
        // cerr<<tmp[0]<<" "<<tmp[1]<<endl;
        // cerr<<"q: ";
        // for(auto it : q) cerr<<it<<" "; cerr<<endl;
        ans++;
        tmp = getMin();
    }
    if(tmp[0] != INF || tmp[1] != INF) ans += min(tmp[0], tmp[1]);
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 