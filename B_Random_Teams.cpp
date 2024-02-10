#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> inv(N);

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
    int n, m; cin>>n>>m;
    int mn, mx;
    int p = n / m;
    int rem = n % m;
    mn = (m - rem) * (p * (p - 1)) / 2;
    mn += rem * p * (p + 1) / 2;
    int mxTeam = n - m + 1;
    mx = mxTeam * (mxTeam - 1) / 2;
    cout<<mn<<" "<<mx<<endl;
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