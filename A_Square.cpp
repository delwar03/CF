#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

void solve() {
    set<vector<int>> st;
    for(int i = 0; i < 4; i++) {
        int x, y; cin>>x>>y;
        st.insert({x, y});
    }
    int a = (*st.begin())[1];
    st.erase(st.begin());
    int b = (*st.begin())[1];

    cout<<(a - b) * (a - b)<<endl;
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