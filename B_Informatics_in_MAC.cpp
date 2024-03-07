#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> pre(n + 1), suf(n + 1);
    int mex = 0;
    set<int> st;
    for(int i = 0; i < n; i++) {
        st.insert(v[i]);
        while(st.count(mex)) mex++;
        pre[i] = mex;
    }
    mex = 0;
    st.clear();
    for(int i = n - 1; i >= 0; i--) {
        st.insert(v[i]);
        suf[i + 1] = mex;
        while(st.count(mex)) mex++;
    }
    // cout<<"pre: ";
    // for(auto it : pre) cout<<it<<" "; cout<<endl;
    // cout<<"suf: ";
    // for(auto it : suf) cout<<it<<" "; cout<<endl;
    for(int i = 0; i < n - 1; i++) {
        if(pre[i] == suf[i + 1]) {
            cout<<2<<endl;
            cout<<1<<" "<<i + 1<<endl;
            cout<<i + 2<<" "<<n<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 