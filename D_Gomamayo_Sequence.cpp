#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<int> c(n);
    for(auto &x : c) cin>>x;
    vector<int> starts_with_zero(n), starts_with_one(n), ends_with_zero(n), ends_with_one(n);
    int f = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] - '0' == f) {
            starts_with_zero[i] = i == 0 ? 0 : starts_with_zero[i - 1];
            starts_with_one[i] = i == 0 ? c[i] : starts_with_one[i - 1] + c[i];
        } else {
            starts_with_zero[i] = i == 0 ? c[i] : starts_with_zero[i - 1] + c[i];
            starts_with_one[i] = i == 0 ? 0 : starts_with_one[i - 1];
        }
        f ^= 1;
    }
    // cerr<<"starts_with_zero: ";
    // for(auto it : starts_with_zero) cerr<<it<<" "; cerr<<endl;
    // cerr<<"starts_with_one: ";
    // for(auto it : starts_with_one) cerr<<it<<" "; cerr<<endl;
    f = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] - '0' == f) {
            ends_with_zero[i] = i == n - 1 ? 0 : ends_with_zero[i + 1];
            ends_with_one[i] = i == n - 1 ? c[i] : ends_with_one[i + 1] + c[i];
        } else {
            ends_with_zero[i] = i == n - 1 ? c[i] : ends_with_zero[i + 1] + c[i];
            ends_with_one[i] = i == n - 1 ? 0 : ends_with_one[i + 1];
        }
        f ^= 1;
    }
    // cerr<<"ends_with_zero: ";
    // for(auto it : ends_with_zero) cerr<<it<<" "; cerr<<endl;
    // cerr<<"ends_with_one: ";
    // for(auto it : ends_with_one) cerr<<it<<" "; cerr<<endl;
    int ans = INF;
    if(n & 1) {
        for(int i = 0; i < n - 1; i++) {
            ans = min(ans, starts_with_zero[i] + ends_with_one[i + 1]);
            ans = min(ans, starts_with_one[i] + ends_with_zero[i + 1]);
        }
    } else {
        for(int i = 0; i < n - 1; i++) {
            ans = min(ans, starts_with_zero[i] + ends_with_zero[i + 1]);
            ans = min(ans, starts_with_one[i] + ends_with_one[i + 1]);
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