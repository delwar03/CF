#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve() {
    string s; cin>>s;
    int ans = 0;
    int n = s.size();
    int cnt_b = 0;

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'b') {
            cnt_b++;
        } else {
            ans = (ans + cnt_b) % M;
            cnt_b = (cnt_b * 2) % M;
        }
    }
    
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
