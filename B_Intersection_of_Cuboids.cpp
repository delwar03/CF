#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    vector<vector<int>> v;
    vector<int> tmp;
    for(int i = 0; i < 6; i++) {
        int x; cin>>x;
        tmp.push_back(x);
    }
    v.push_back(tmp);
    tmp.clear();
    for(int i = 0; i < 6; i++) {
        int x; cin>>x;
        tmp.push_back(x);
    }
    v.push_back(tmp);
    tmp.clear();
    
    int f = (v[1][0] >= v[0][3] || v[1][1] >= v[0][4] || v[1][2] >= v[0][5]) || (v[0][0] >= v[1][3] || v[0][1] >= v[1][4] || v[0][2] >= v[1][5]);
    cout<<(!f ? "Yes" : "No")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/