#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
    }

    string s; cin>>s;
    int l = 0, r = n - 1;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') l++;
        else r--;
    }
    // cout<<l<<" "<<r<<endl;
    vector<int> ans;
    int prod = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'L') {
            prod = (prod * v[--l]) % m;
        } else {
            prod = (prod * v[++r]) % m;
        }
        ans.push_back(prod);
    }
    for(int i = n - 1; i >= 0; i--) {
        cout<<ans[i]<<" \n"[i == 0];
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