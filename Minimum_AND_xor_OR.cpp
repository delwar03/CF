#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());
    int mn = INF;
    for(int i = 1; i < n - 1; i++) {
        mn = min({mn, v[i] ^ v[i + 1], v[i] ^ v[i - 1]});
    }
    cout<<mn<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/