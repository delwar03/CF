#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e4 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    pair<pair<int, int>, pair<int, string>> p[n];
    for(int i = 0; i < n; i++) {
        int a, b, c;
        string s; cin>>s>>a>>b>>c;
        a *= -1; b *= -1;
        p[i].first.first = a;
        p[i].first.second = b;
        p[i].second.first = c;
        p[i].second.second = s;
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++) cout<<p[i].second.second<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 