#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    string p = s;
    reverse(p.begin(), p.end());
    // cout<<s<<" "<<p<<endl;
    if(s == p) {
        cout<<s<<endl;
    } else {
        int i = 0, j = s.size() - 1;
        while(s[i] == s[j]) i++, j--;
        if(s[i] < s[j]) cout<<s<<endl;
        else cout<<p<<s<<endl;
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