       

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

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void solve() {
    int n, c; cin>>n>>c;
    vector<int> v(n + 1);
    multiset<pair<int, int>> st;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        v[i] = x;
        if(i > 1) st.insert({c * i - x, i});
    }
    int sum = v[1];
    for(auto it : st) {
        sum += v[it.second];
        if(sum < it.second * c) {cout<<"No\n"; return;}
    }
    cout<<"Yes\n";
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