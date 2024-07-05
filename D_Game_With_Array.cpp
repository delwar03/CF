#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, s; cin>>n>>s;
    if(s >= 2 * n) {
        cout<<"YES"<<endl;
        for(int i = 0; i < n - 1; i++) cout<<"2 ";
        cout<<s - 2 * (n - 1)<<endl;
        cout<<"1"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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
    1 -> 1
    2 -> 2
    4 -> 4
    5 -> 2
o/p: 
*/ 
