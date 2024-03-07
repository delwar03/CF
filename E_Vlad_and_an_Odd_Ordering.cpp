#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    int prv = 0, cur = 0, ind = 2;
    while(1) {
        cur += (n + ind - ind / 2) / ind;
        if(k <= cur) {
            k -= prv;
            cout<<(2 * k - 1) * ind / 2<<endl;
            return;
        }
        ind *= 2;
        prv = cur;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 