#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    int a = 1, m = n;
    while(m) {
        if((m & 1) == 0) {
            a *= 2;
        } else {
            break;
        }
        m >>= 1;
    }
    if(a == n) {
        cout<<"-1"<<endl;
    } else {
        cout<<a<<" "<<n - a<<endl;
    }
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