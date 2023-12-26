#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

bool isPalindrom(string s) {
    int l = s.size();
    for(int i = 0; 2 * i < l; i++) {
        if(s[i] != s[l - 1 - i]) return false;
    }
    return true;
}

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    if(k == 0) {cout<<"1\n"; return; }
    if(isPalindrom(s)) cout<<"1\n";
    else cout<<"2\n";
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