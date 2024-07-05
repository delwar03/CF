#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void solve() {
    int n, m; cin>>n>>m;
    string s; cin>>s;
    map<int, int> ind;
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        ind[x]++;
    }
    string c; cin>>c;
    sort(c.rbegin(), c.rend());
    for(auto it : ind) {
        int i = it.first;
        s[i - 1] = c.back();
        c.pop_back();
    }
    cout<<s<<endl;
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