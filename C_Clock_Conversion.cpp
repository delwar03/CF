#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    string s; cin>>s;
    string h = "", m = "";
    h += s[0];
    h += s[1];
    m += s[3];
    m += s[4];

    // cerr<<h<<" "<<m<<endl;
    int f = 0;
    int hour = stoi(h);
    int mint = stoi(m);
    if(hour >= 12) f = 1;
    if(hour > 12) hour -= 12;
    if(hour == 0) hour = 12;
    h = to_string(hour);
    m = to_string(mint);
    if(h.size() < 2) h = "0" + h;
    if(m.size() < 2) m = "0" + m;
    cout<<h<<":"<<m<<(f ? " PM" : " AM")<<endl;
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