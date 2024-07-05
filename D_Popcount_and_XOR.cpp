#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, b, c; cin>>a>>b>>c;
    int popCnt = __builtin_popcountll(c);
    int d = (a + b - popCnt) / 2;
    if(d < 0 || ((a + b - popCnt) & 1) || (d > min(a, b)) || (popCnt + d > 60)) {cout<<"-1"<<endl; return; } 

    int x = 0, y = 0;
    int cnt = 0, cnt2 = 0;
    for(int i = 0; i < 60; i++) {
        if((c >> i) & 1) {
            if(cnt < a - d) x |= (1LL << i);
            else y |= (1LL << i);
            cnt++;
        } else if(cnt2 < d) {
            x |= (1LL << i);
            y |= (1LL << i);
            cnt2++;
        }
    }
    cout<<x<<" "<<y<<endl;
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