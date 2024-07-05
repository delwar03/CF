#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i < n - 5) {
            if(s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p' && s[i + 3] == 'i' && s[i + 4] == 'e') {
                ans++;
                i += 4;
                continue;
            }
        }
        if(i < n - 2) {
            if((s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') || (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')) {
                ans++;
                i += 2;
            }
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
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 