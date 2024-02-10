#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, x; cin>>n>>x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    for(int i = 0; i < n; i++) {
        if(v[i] == x) {
            cout<<i + 1<<endl;
            return;
        }
    }

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