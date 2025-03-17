#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    string s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(s[i] == t[j] || s[i] == '?') {
            s[i] = t[j];
            i++;
            j++;
        } else {
            i++;
        }
    }

    if(j == m) {
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                s[i] = 'x';
            }
        }
        cout<<"YES"<<endl;
        cout<<s<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/