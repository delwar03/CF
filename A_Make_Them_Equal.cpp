#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    set<int> st;
    for(int i = 0; i < n; i++) {int x; cin>>x; st.insert(x);}
    if(st.size() > 3) {cout<<"-1\n"; return;}
    vector<int> v(st.begin(), st.end());
    if(v.size() == 1) {cout<<"0\n"; return;}
    if(v.size() == 2) {
        int d = v[1] - v[0];
        if(d & 1) cout<<d<<endl;
        else cout<<d / 2<<endl;
        return;
    }

    if(v[1] - v[0] == v[2] - v[1]) {
        cout<<v[1] - v[0]<<endl;
    } else {
        cout<<"-1\n";
    }
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