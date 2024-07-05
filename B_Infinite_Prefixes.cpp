#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, x; cin>>n>>x;
    string s; cin>>s;

    int last = 2 * count(s.begin(), s.end(), '0') - n;

    int ans = 0, cur = 0;

    for(auto ch : s) {
        if(last == 0) {
            if(cur == x) {
                cout<<-1<<endl;
                return;
            }
        } else {
            if((x - cur) % last == 0) {
                if((x - cur) / last >= 0) {
                    ans++;
                }
            }
        }
        cur += (ch == '0' ? 1 : -1);
    }
    cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/