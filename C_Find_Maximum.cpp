#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
vector<int> freq(N, 0);

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    string s; cin>>s;

    vector<int> pref(n + 1, 0), suff(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + v[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') {
            suff[i] = suff[i + 1] + v[i];
        } else {
            suff[i] = suff[i + 1];
        }
    }

    // cerr<<"pref: ";
    // for(auto it : pref) cerr<<it<<" "; cerr<<endl;
    // cerr<<"suff: ";
    // for(auto it : suff) cerr<<it<<" "; cerr<<endl;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ans += v[i];
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') {
            int cnt = pref[i];
            cnt += suff[i + 1];
            ans = max(ans, cnt);
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
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
