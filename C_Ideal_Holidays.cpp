#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, a, b; cin>>n>>a>>b;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        st.insert(x % (a + b));
    }
    vector<int> d;
    for(auto it : st) d.push_back(it);
    d.push_back(d[0] + a + b);
    int k = d.size();
    for(int i = 0; i < k - 1; i++) {
        if(d[i + 1] - d[i] > b) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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