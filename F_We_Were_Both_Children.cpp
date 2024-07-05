#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e9 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    for(auto &x : v) {
        cin>>x;
        if(x <= n) {
            mp[x]++;
        }
    }

    vector<int> cnt(n + 1);

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            cnt[j] += mp[i];
        }
    }

    int mx = *max_element(cnt.begin(), cnt.end());

    cout<<mx<<endl;
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