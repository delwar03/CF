#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int dx = 0, dy = 0;
    string ans;
    map<char, int> mp;

    for(auto ch : s) {
        if(ch == 'N') {
            mp[ch]++;
            if(mp[ch] % 2) {
                ans += "R";
                dy++;
            } else {
                ans += "H";
                dy--;
            }
        } else if(ch == 'S') {
            mp[ch]++;
            if(mp[ch] % 2) {
                ans += "R";
                dy--;
            } else {
                ans += "H";
                dy++;
            }
        } else if(ch == 'E') {
            mp[ch]++;
            if(mp[ch] % 2) {
                ans += "H";
                dx++;
            } else {
                ans += "R";
                dx--;
            }
        } else {
            mp[ch]++;
            if(mp[ch] % 2) {
                ans += "H";
                dx--;
            } else {
                ans += "R";
                dx++;
            }
        }
    }
    // cerr<<dx<<" "<<dy<<endl;
    // cerr<<ans<<endl;
    if(dx || dy || ans.find("H") == string::npos || ans.find("R") == string::npos) {
        cout<<"NO"<<endl;
    } else {
        cout<<ans<<endl;
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