#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m, k; cin>>n>>m>>k;
    int lcm = n * m / __gcd(n, m);

    auto hobe = [&] (int x) {
        int ind = (x / n) + (x / m) - 2 * (x / lcm);
        return ind >= k;
    };

    int l = 0, r = INF;
    while(l < r) {
        int mid = (l + r) / 2;
        if(hobe(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout<<l<<endl;
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