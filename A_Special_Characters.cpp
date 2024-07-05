#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
vector<int> g[N];
vector<int> dist(N, INF);

void solve() {
    int n; cin>>n;
    if(n & 1) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        int f = 1;
        for(int i = 0; i < n / 2; i++) {
            if(f) cout<<"AA";
            else cout<<"BB";
            f ^= 1;
        }
        cout<<endl;
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