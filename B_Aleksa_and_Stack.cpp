#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    v[0] = 1; v[1] = 3;
    for(int i = 2; i < n; i++) {
        v[i] = v[i - 1] + 1;
        while((3 * v[i]) % (v[i - 1] + v[i - 2]) == 0) v[i]++;
    }
    for(auto it : v) cout<<it<<" "; cout<<endl;
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