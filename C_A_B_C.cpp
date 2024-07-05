#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> A(n);
    for(auto &a : A) cin>>a;
    int m; cin>>m;
    vector<int> B(m);
    for(auto &b : B) cin>>b;
    int l; cin>>l;
    vector<int> C(l);
    for(auto &c : C) cin>>c;
    set<int> st;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < l; k++) {
                st.insert(A[i] + B[j] + C[k]);
            }
        }
    }
    int q; cin>>q;
    while(q--) {
        int x; cin>>x;
        cout<<(st.count(x) ? "Yes" : "No")<<endl;
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