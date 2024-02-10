#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, k;

int f(int x) {
    return x - x / n;
}

void solve() {
    cin>>n>>k;
    int l = 1, r = INF, ans;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(f(m) < k) {
            l = m + 1;
        } else {
            ans = m;
            r = m - 1;
        }
    }
    cout<<ans<<endl;
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