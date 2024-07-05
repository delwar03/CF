#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;

vector<int> LCM(100);

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int a, b; cin>>a>>b;
    int ans = b - a;
    int opr = 1, tmp = a;
    while(tmp < b) {
        ans = min(ans, opr + abs((tmp | b) - b));
        tmp++;
        opr++;
    }
    opr = 1; tmp = b;
    while(tmp <= 2 * b - a) {
        ans = min(ans, opr + abs((a | tmp) - tmp));
        opr++;
        tmp++;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LCM[0] = LCM[1] = 1;
    for(int i = 2; i < 100; i++) LCM[i] = lcm(LCM[i - 1], i);

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