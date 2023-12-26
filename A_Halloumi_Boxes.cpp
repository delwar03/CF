#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    bool isSorted = true;
    for(int i = 0; i < n - 1; i++) {
        if(v[i + 1] < v[i]) {
            isSorted = false;
            break;
        }
    }
    if(k > 1) cout<<"YES\n";
    else if(k == 1 && isSorted) cout<<"YES\n";
    else cout<<"NO\n";
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