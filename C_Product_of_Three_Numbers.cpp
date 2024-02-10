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
    set<int> di;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            di.insert(i);
            n /= i;
        }
        if(di.size() >= 2) break;
    }
    if(n > 1 ) di.insert(n);
    // for(auto it : di) cout<<it<<" "; cout<<endl;
    if(di.size() < 3) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        for(auto it : di) cout<<it<<" "; cout<<endl;
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