#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    string s; cin>>s;
    map<int, int> mp;
    int cnt = 0;
    for(auto ch : s) {
        cnt += (ch == '(' ? 1 : -1);
        mp[cnt]++;
    }
    cout<<(cnt == 0) * (mp.begin()->second)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 