#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, m;

void solve() {
    cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;
    int ans = 1;
    for(int j = 0; j < m; j++) {
        set<char> st;
        for(int i = 0; i < n; i++) {
            st.insert(v[i][j]);
        }
        int cnt = st.size();
        ans = (ans * cnt) % M;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 