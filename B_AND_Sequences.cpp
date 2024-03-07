#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
int fact[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    int mn = INF;
    for(auto &x : v) {
        cin>>x;
        mp[x]++;
        if(x < mn) mn = x;
    }
    for(auto it : v) {
        if((mn & it) != mn) {
            cout<<0<<endl;
            return;
        }
    }
    int ans = 1;
    ans = (ans * mp[mn] * (mp[mn] - 1)) % M;
    ans = (ans * fact[n - 2]) % M;
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++) {
        fact[i] = (i * fact[i - 1]) % M;
    }

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