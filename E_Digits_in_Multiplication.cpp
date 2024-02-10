#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int f(int a, int b) {
    int ans = 1, cnt = 0;
    while(a) {
        cnt++;
        a /= 10;
    }
    ans = max(ans, cnt);
    cnt = 0;
    while(b) {
        cnt++;
        b /= 10;
    }
    ans = max(ans, cnt);
    return ans;
}

void solve() {
    int n; cin>>n;
    int mxDiv = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) mxDiv = i;
    }
    cout<<f(mxDiv, n / mxDiv)<<endl;
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
i/p: 2
     3
     5 4
     7 6
     11 3
     4
     2 1
     3 2
     5 3
     7 1
o/p: Case 1: 69
     Case 2: 113
*/ 