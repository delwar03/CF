       

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
int n;
vector<int> v;

bool isSorted(int l, int r) {
    r = min(n, r);
    l = min(n, l);
    for(int i = l; i < r; i++) {
        if(v[i + 1] < v[i]) return false;
    }
    return true;
}

void solve() {
    cin>>n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
    }
    int ind = 1;
    while(1) {
        if(!isSorted(ind + 1, (ind << 1LL))) {cout<<"NO\n"; return;}
        ind <<= 1LL;
        if(ind > n) break;
    }
    cout<<"YES\n";
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