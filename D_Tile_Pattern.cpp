#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, q; cin>>n>>q;
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        char ch = s.back();
        s.pop_back();
        s = ch + s;
        v.push_back(s);
    }
    int val[n][n];
    memset(val, 0, sizeof val);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == 'B') val[i][j]++;
        }
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
o/p: 
*/ 