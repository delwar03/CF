#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> ans;
    int m = n, val = 1;
    while(m) {
        if(m == 1) {
            cout<<val<<endl;
            return;
        } else if(m == 2) {
            cout<<val<<" "<<2 * val<<endl;
            return;
        } else if(m == 3) {
            cout<<val<<" "<<val<<" "<<3 * val<<endl;
            return;
        }
        for(int i = 1; i <= m; i += 2) {
            cout<<val<<" ";
        }
        m /= 2; val *= 2;
    }
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