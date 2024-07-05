#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    string str; cin>>str;
    int r = -1, p = -1, s = -1;
    vector<int> loses(n);

    for(int i = n - 1; i >= 0; i--) {
        if(str[i] == 'R') {
            loses[i] = p;
            r = i;
        } else if(str[i] == 'P') {
            loses[i] = s;
            p = i;
        } else {
            loses[i] = r;
            s = i;
        }
    }
    // for(auto it : loses) cerr<<it<<" "; cerr<<endl;

    string ans(n, '?');

    for(int i = n - 1; i >= 0; i--) {
        if(loses[i] == -1) {
            ans[i] = str[i];
        } else {
            ans[i] = ans[loses[i]];
        }
    }
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