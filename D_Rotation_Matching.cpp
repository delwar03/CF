#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(N, 0), b(n);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a[x] = i;
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        b[i] = (a[b[i]] - i + n) % n;
    }
    vector<int> freq(N, 0);
    int ans = 0, rot = 0;
    for(auto it : b) {
        freq[it]++;
        if(freq[it] > ans) {ans = freq[it]; rot = it; }
    }
    cout<<ans<<endl;
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
}
 
/*
i/p: 
o/p: 
*/ 