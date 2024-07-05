#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m; cin>>n>>m;
    multiset<int> st;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        st.insert(x);
    }
    int cost = 0;
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        auto it = st.lower_bound(x);
        if(it == st.end()) {
            cout<<-1<<endl;
            return;
        }
        cost += *it;
        st.erase(it);
    }
    cout<<cost<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/