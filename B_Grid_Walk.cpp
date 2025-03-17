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
    int n, m; cin>>n>>m;
    vector<string> v(n);
    int x, y; cin>>x>>y;
    --x; --y;
    for(auto &ele : v) cin>>ele;

    auto isValid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && v[i][j] == '.';
    };

    string dir; cin>>dir;
    for(auto ch : dir) {
        if(ch == 'U') {
            if(isValid(x - 1, y)) x--;
        } else if(ch == 'D') {
            if(isValid(x + 1, y)) x++;
        } else if(ch == 'L') {
            if(isValid(x, y - 1)) y--;
        } else {
            if(isValid(x, y + 1)) y++;
        }
    }
    cout<<x + 1<<" "<<y + 1<<endl;
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