       

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
    int n, m; cin>>n>>m;
    string a, b; cin>>a>>b;
    bool hobe = true, good = true;
    set<char> st;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            good = false;
            st.insert(a[i]);
        }
    }
    if(good) {
        cout<<"Yes\n";
        return;
    }
    for(int i = 0; i < m - 1; i++) {
        if(b[i]  == b[i + 1]) {
            hobe = false;
            break;
        }
    }
    if(!hobe) {cout<<"No\n"; return;}
    if(st.size() > 1) {cout<<"No\n"; return;}
    if(*st.begin() != b[0] && *st.begin() != b[m - 1]) cout<<"Yes\n";
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