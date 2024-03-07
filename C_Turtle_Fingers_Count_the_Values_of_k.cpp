#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, b, l; cin>>a>>b>>l;
    vector<int> v1, v2;
    int p = 1;
    while(p <= l) {
        v1.push_back(p);
        p *= a;
    }
    p = 1;
    while(p <= l) {
        v2.push_back(p);
        p *= b;
    }
    set<int> st;
    for(auto &x : v1) {
        for(auto &y : v2) {
            int z = x * y;
            if(l % z == 0) {
                st.insert(l / z);
            }
        }
    }
    cout<<(int) st.size()<<endl;
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