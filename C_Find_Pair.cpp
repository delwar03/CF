#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    map<int, int> mp;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        st.insert(x);
        mp[x]++;
    }
    int prv = 0;
    for(auto a : st) {
        int cur = prv + n * mp[a];
        if(cur >= k) {
            // cerr<<"cur: "<<cur<<", prv: "<<prv<<endl;
            k -= prv;
            int prv2 = 0;
            for(auto b : st) {
                int cur2 = prv2 + mp[b] * mp[a];
                if(cur2 >= k) {
                    cout<<a<<" "<<b<<endl;
                    return;
                }
                prv2 = cur2;
            }
        }
        prv = cur;
    }
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