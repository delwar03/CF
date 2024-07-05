#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    int x = 0, y = 0, pos = 0, neg = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            x += a[i];
        } else if(b[i] > a[i]) {
            y += b[i];
        } else if(a[i] == 1) {
            pos++;
        } else if(a[i] == -1) {
            neg++;
        }
    }
    while(pos--) {
        if(x > y) {
            y++;
        } else {
            x++;
        }
    }
    while(neg--) {
        if(x > y) {
            x--;
        } else {
            y--;
        }
    }
    cout<<min(x, y)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/