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
    int n; cin>>n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int x; char ch; cin>>x>>ch;
        if(ch == 'L') {
            v.push_back({x, 0});
        } else {
            v.push_back({x, 1});
        }
    }

    auto f = [&] (int l, int r) {
        int res = 0, L = l, R = r;
        for(auto it : v) {
            if(it.ss == 0) {
                res += abs(L - it.ff);
                L = it.ff;
            } else {
                res += abs(R - it.ff);
                R = it.ff;
            }
        }
        return res;
    };

    int ans = INF;

    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            ans = min(ans, f(i, j));
        }
    }
    cout<<ans<<endl;
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