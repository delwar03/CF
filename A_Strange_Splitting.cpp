#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    set<int> st;
    for(auto &x : v) {
        cin>>x;
        st.insert(x);
    }
    if(st.size() == 1) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        if(v[n - 1] != v[1]) {
            cout<<"R";
            for(int i = 1; i < n; i++) cout<<"B"; cout<<endl;
        } else {
            cout<<"RR";
            for(int i = 2; i < n; i++) cout<<"B"; cout<<endl;
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