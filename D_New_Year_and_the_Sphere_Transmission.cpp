#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    auto bs = [&] (int i) {
        int l = 0, r = n, m, can;
        while(l <= r) {
            m = (l + r) / 2;
            if(1 + i * m <= n) {
                can = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // cerr<<"can: "<<can<<endl;
        can++;
        return can + i * (can * (can - 1) / 2);
    };

    set<int> st;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            st.insert(bs(i));
            st.insert(bs(n / i));
        }
    }

    for(auto it : st) cout<<it<<" ";
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