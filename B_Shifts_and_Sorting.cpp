#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    string s; cin>>s;
    int ans = 0, n = s.size(), cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(cnt1)
                ans += cnt0 * (cnt1 + 1);
            cnt1++;
            cnt0 = 0;
        } else {
            cnt0++;
        }
    }
    if(cnt1)
        ans += cnt0 * (cnt1 + 1);
    cout<<ans<<endl;
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