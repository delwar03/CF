#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 504;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

// 0 2

void solve() {
    int n; cin>>n;
    multiset<int> st;
    vector<int> cnt(34, 0);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        st.insert(x);
        for(int i = 33; i >= 0; i--) {
            if((x >> i) & 1) {
                cnt[i] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 33; i >= 0; i--) {
        if(!cnt[i]) {
            vector<int> del;
            for(int x : st) {
                if(x >= (1LL << i)) {
                    if(!((x >> i) & 1)) {
                        del.push_back(x);
                    }
                }
            }
            ans += del.size();
            for(int x : del) {
                st.erase(st.find(x));
            }
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
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/