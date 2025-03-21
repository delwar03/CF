#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    string s; cin>>s;
    int l = s.size();
    if(l <= 2) {cout<<"NO"<<endl; return; }
    string tmp = "";
    for(int i = 2; i < l; i++) tmp += s[i];
    int now = stoll(tmp), cnt = 0;
    int cur = now;
    while(cur) {    
        cur /= 10;
        cnt++;
    }
    if(s[0] == '1' && s[1] == '0' && now >= 2 && cnt == l - 2) {
        cout<<"YES"<<endl;
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