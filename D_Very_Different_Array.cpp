#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    multiset<int> st;
    for(int i = 0; i < n; i++) { int x; cin>>x; st.insert(x);}
    multiset<int> st1;
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        st1.insert(x);
    }
    int ans = 0, cnt = 0;
    while(st.size()) {
        if(abs((*st.begin()) - (*st1.rbegin())) > abs((*st.rbegin()) - (*st1.begin()))) {
            ans += abs((*st.begin()) - (*st1.rbegin()));
            st.erase(st.begin());
            auto it = st1.end(); --it;
            st1.erase(it);
        } else {
            ans += abs((*st.rbegin()) - (*st1.begin()));
            auto it = st.end(); --it;
            st.erase(it);
            st1.erase(st1.begin());
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 