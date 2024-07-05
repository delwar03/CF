#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
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

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    int sum = 0;
    for(auto &x : v) {cin>>x; sum += x;}
    int mx = -INF, mxSum = 0;
    for(int i = 0; i < n; i++) {
        mxSum += v[i];
        mx = max(mx, mxSum);
        if(mxSum < 0) mxSum = 0;
    }
    // cout<<mx<<endl;
    if(mx < 0) mx = 0;
    for(int i = 0; i < k; i++) {
        sum = (sum + mx) % M;
        mx = (mx + mx) % M;
    }
    sum = (sum + M) % M;
    cout<<sum<<endl;
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