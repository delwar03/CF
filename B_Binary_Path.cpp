#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s1, s2; cin>>s1>>s2;
    string path = "";
    int ind = n;
    path += s1[0];
    for(int i = 1; i < n; i++) {
        if(ind == n && s1[i] > s2[i - 1]) ind = i;
        if(ind == n) path += s1[i];
        else path += s2[i - 1];
    }
    path += s2.back();
    int cnt = 1;
    ind--;
    // cout<<"ind: "<<ind<<endl;
    while(ind > 0) {
        if(s1[ind] == s2[ind - 1]) cnt++;
        else break;
        ind--;
    }
    cout<<path<<endl;
    cout<<cnt<<endl;
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