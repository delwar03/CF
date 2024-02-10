#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin>>n;
    vector<int> a(n), d(n);
    for(auto &x : a) cin>>x;
    for(auto &x : d) cin>>x;

    vector<int> pref(1005, 0);
    for(int i = 0; i < n; i++) {
        pref[a[i]]++;
        pref[d[i]]--;
    }
    for(int i = 1; i < 1005; i++) pref[i] += pref[i - 1];
    // for(int i = 0; i < 1005; i++) cout<<pref[i]<<" "; cout<<endl;
    cout<<*max_element(pref.begin(), pref.end())<<endl;
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