#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) {cin>>x;}
    int cnt1 = 0, cnt2 = 0, i = 0;
    while(v[i] == v[0]) cnt1++, i++;
    i = n - 1;
    while(v[i] == v[n  - 1]) cnt2++, i--;
    int del = max(cnt1, cnt2);
    if(v[0] == v[n - 1]) del = cnt1 + cnt2;
    cout<<max(0LL, n - del)<<endl;
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