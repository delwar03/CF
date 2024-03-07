#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        v[i] %= 3;
        sum += v[i];
        mp[v[i]]++;
    }
    if(sum % 3 == 0) cout<<0<<endl;
    else if(mp.count(sum%3)) cout<<1<<endl;
    else cout<<3 - sum % 3<<endl;
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