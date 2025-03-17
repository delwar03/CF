#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];

    vector<int> BIT(2 * n);

    auto add = [&] (int i, int x) {
        for(; i < n; i += i & -i) BIT[i] += x;
    };

    auto sum = [&] (int i) {
        int res = 0;
        for(; i > 0; i -= i & -i) res += BIT[i];
        return res;
    };

    auto qur = [&] (int l, int r) {
        if(l > r) return 0LL;
        return sum(r) - sum(l - 1);
    };

    for(int i = 1; i <= n; i++) add(i, a[i]);

    set<int> st;
    for(int i = 1; i <= n; i++) {
        if(b[i] >= 2) {
            st.insert(i);
        }
    }
    st.insert(n + 1);

    auto query = [&] (int l, int r) {
        int L = l, R = r, res = 0;
        while(L <= R) {
            auto it = st.lower_bound(L);
            int ind = min(R, *it);
            res += qur(L, ind - 1);
            res = max(res + a[ind], res * b[ind]);
            L = ind + 1;
        }
        return res;
    };

    int q; cin>>q;
    while(q--) {
        int ty; cin>>ty;
        if(ty == 1) {
            int i, x; cin>>i>>x;
            add(i, -a[i] + x);
            a[i] = x;
        } else if(ty == 2) {
            int i, x; cin>>i>>x;
            if(b[i] >= 2) st.erase(i);
            b[i] = x;
            if(b[i] >= 2) st.insert(i);
        } else {
            int l, r; cin>>l>>r;
            cout<<query(l, r)<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/