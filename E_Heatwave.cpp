#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
double PI = acos(-1.0);
double eps = 1e-5;

void solve() {
    int n, k, x; cin>>n>>k>>x;
    int ans = (x * (x + 1) / 2) % M;
    ans = (ans * k) % M;
    ans = (ans * (n / x)) % M;
    int p = n % x;
    int ans1 = (p * (p + 1) / 2) % M;
    ans1 = (ans1 * k) % M;
    
    cout<<(ans + ans1) % M<<endl;
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