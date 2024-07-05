#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    for(int k = n; k > 0; k--) {
        bool hobe = true;
        int f = 0;
        vector<int> flip(n, 0);

        for(int i = 0; i <= n - k; i++) {
            if((f + s[i] - '0') % 2 == 0) {
                f ^= 1;
                flip[i + k - 1] = 1;
            }
            f ^= flip[i];
        }

        for(int i = n - k + 1; i < n; i++) {
            if((f + s[i] - '0') % 2 == 0) {
                hobe = false;
                break;
            }
            f ^= flip[i];
        }

        if(hobe) {
            cout<<k<<endl;
            return;
        }
    }
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