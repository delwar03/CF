#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k, q; cin>>n>>k>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    for(int i = 0; i < n; i++) v[i] += n - i;

    vector<int> ans(n + 1, 0), freq(2 * n + 5);
    multiset<int> st;
    int cnt = 0;

    auto upd = [&] (int x, int val) {
        auto it = st.find(freq[x]);
        if(it != st.end()) {
            st.erase(it);
        }
        freq[x] += val;
        st.insert(freq[x]);
    };

    for(int i = 0; i < n; i++) {
        upd(v[i], +1);
        cnt++;
        if(cnt == k) {
            ans[i - (k - 1)] = k - *(--st.end());
            upd(v[i - (k - 1)], -1);
            cnt--;
        }
    }

    // cerr<<"ans: ";
    // for(int i = 0; i < n; i++) cerr<<ans[i]<<" "; cerr<<endl;

    for(int i = 1; i < n + 1; i++) ans[i] += ans[i - 1];

    while(q--) {
        int l, r; cin>>l>>r;
        r -= (k - 1);
        --l; --r;
        assert(l == r);
        
        int res = ans[r] - (l - 1 >= 0 ? ans[l - 1] : 0);
        cout<<res<<endl;
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