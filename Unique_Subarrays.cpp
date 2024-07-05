#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int ans = 0;
    set<int> st;
    int i = 0, j = 0;
    while(i < n) {
        while(j < n && !st.count(v[j])) {
            st.insert(v[j++]);
        }
        int sz = (j - i);
        ans += sz * (sz + 1) / 2;
        st.erase(v[i++]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/