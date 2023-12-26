       

        //  ▄████▄   ▒█████  ▓█████▄ ▓█████ 
        // ▒██▀ ▀█  ▒██▒  ██▒▒██▀ ██▌▓█   ▀ 
        // ▒▓█    ▄ ▒██░  ██▒░██   █▌▒███   
        // ▒▓▓▄ ▄██▒▒██   ██░░▓█▄   ▌▒▓█  ▄ 
        // ▒ ▓███▀ ░░ ████▓▒░░▒████▓ ░▒████▒
        // ░ ░▒ ▒  ░░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░
        //   ░  ▒     ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░
        // ░        ░ ░ ░ ▒   ░ ░  ░    ░   
        // ░ ░          ░ ░     ░       ░  ░
        // ░                  ░             
 

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, x; cin>>n>>x;
    vector<int> v(n);
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) cin>>v[j];
        for(int j = 0; j < n; j++) {
            if((x | v[j]) == x) ans |= v[j];
            else break;
        }
    }
    if(ans == x) cout<<"Yes\n";
    else cout<<"No\n";
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