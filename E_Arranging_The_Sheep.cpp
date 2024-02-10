#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int ans = 0;
    int cnt = 0;
    for(auto ch : s) {
        cnt += (ch == '*');
    }
    cnt = (cnt + 1) / 2;
    int pos = 0, cnt1 = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '*') cnt1++;
        if(cnt1 == cnt) {
            pos = i;
            break;
        }
    }

    cnt = pos;
    for(int i = pos; i >= 0; i--) {
        if(s[i] == '*') {
            ans += cnt - i;
            cnt--;
        }
    }
    // cout<<pos<<endl;
    cnt = pos + 1;
    for(int i = pos + 1; i < n; i++) {
        if(s[i] == '*') {
            ans += i - cnt;
            cnt++;
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
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 