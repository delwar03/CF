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
    vector<set<int>> v(n);
    for(int i = 0; i < n; i++) {
        int k; cin>>k;
        for(int j = 0; j < k; j++) {
            int x; cin>>x;
            v[i].insert(x);
        }
    }

    auto getMEX = [&] (set<int> st, int cur) {
        int j = cur;
        while(st.count(j)) j++;
        return j;
    };

    int mx = 0;

    for(int i = 0; i < n; i++) {
        int cur1 = getMEX(v[i], 0);
        mx = max(mx, cur1);
        int cur2 = getMEX(v[i], cur1 + 1);
        mx = max(mx, cur2);
    }

    int ans = 0;

    if(mx <= m) {
        ans = (mx + 1) * mx;
        ans += m * (m + 1) / 2 - mx * (mx + 1) / 2;
    } else {
        ans = (m + 1) * mx;
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