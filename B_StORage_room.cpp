#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin>>v[i][j];
    }
    vector<int> ans(n, (1 << 30) - 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i ^ j) {
                ans[i] &= v[i][j];
                ans[j] &= v[i][j];
            }
        }
    }

    bool hobe = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i ^ j) {
                if(v[i][j] != (ans[i] | ans[j])) {hobe = false; break; }
            }
        }
        if(!hobe) break;
    }
    
    if(hobe) {
        cout<<"YES\n";
        for(auto it : ans) cout<<it<<" "; cout<<endl;
    } else {
        cout<<"NO\n";
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