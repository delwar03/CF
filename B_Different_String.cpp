#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    string s; cin>>s;
    set<char> st(s.begin(), s.end());
    if(st.size() == 1) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[0]) {
                swap(s[0], s[i]);
                break;
            }
        }
        cout<<s<<endl;
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