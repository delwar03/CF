#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> cnt(64);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        int ind = 0;
        while(x) {
            cnt[ind++] += x % k;
            x /= k;
        }
    }
    for(int i = 0; i < 64; i++) {
        if(cnt[i] > 1) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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