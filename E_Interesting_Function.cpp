#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int minVal(int a, int b, int c, int d) {
    vector<int> vec = {a, b, c, d};
    int mn = INF;
    for(int i = 0; i < 4; i++) {
        int tmp = 0;
        for(int j = 0; j < 4; j++) {
            tmp += abs(vec[i] - vec[j]);
        }
        mn = min(mn, tmp);
    }
    return mn;
}

void solve() {
    int l, r; cin>>l>>r;
    int ans = 0;
    while(r) {ans += r; r /= 10;}
    while(l) {ans -= l; l /= 10;}
    
    cout<<ans<<endl;
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