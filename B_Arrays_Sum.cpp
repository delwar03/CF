#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    set<int> st;
    for(auto &x : v) {cin>>x; st.insert(x); }
    int sz = st.size();
    if(k == 1 && sz > 1) {cout<<"-1"<<endl; return; }
    if(sz <= k) {cout<<"1"<<endl; return; }
    int ans = 1;
    sz -= k;
    ans += (sz + k - 2) / (k - 1);
    cout<<ans<<endl;
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