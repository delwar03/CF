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
    int n; cin>>n;
    string s; cin>>s;
    int ans = INF;
    vector<int> v;
    for(auto ch : s) {
        v.push_back(ch - '0');
    }

    auto sum = [&] (vector<int> v) {
        int ans = 0;
        for(auto it : v) {
            if(it == 0) return 0LL;
            if(it != 1) {
                ans += it;
            }
        }
        return max(ans, 1LL);
    };

    for(int i = 0; i < n - 1; i++) {
        vector<int> now;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                now.push_back(10 * v[j] + v[j + 1]);
                j++;
            } else {
                now.push_back(v[j]);
            }
        }
        ans = min(ans, sum(now));
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/