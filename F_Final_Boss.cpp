#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int h, n; cin>>h>>n;
    vector<int> a(n), c(n);
    int sum = 0;

    for(auto &x : a) {cin>>x; sum += x;}
    for(auto &x : c) cin>>x;

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[i] = c[i];
    }

    h -= sum;
    int ans = 1;

    if(h <= 0) {
        cout<<ans<<endl;
    } else {
        int mx = 0;
        multiset<vector<int>> st;
        for(int i = 0; i < n; i++) {
            st.insert({c[i], a[i], i});
        }

        while(st.size()) {
            auto vec = *(st.begin()); 
            st.erase(st.begin());

            ans += vec[0] - mx;
            mx = vec[0];
            h -= vec[1];
            st.insert({vec[0] + mp[vec[2]], vec[1], vec[2]});
            if(h <= 0) {
                cout<<ans<<endl;
                return;
            }
        }
    }
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