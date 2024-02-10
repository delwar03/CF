#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int f = -1, b = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'B') {
            if(f == -1) f = i;
            b = i;
        }
    }
    if(f == -1) cout<<"0"<<endl;
    else cout<<b - f + 1<<endl;
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