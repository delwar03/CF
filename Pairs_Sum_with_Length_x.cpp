#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 504;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

int pwr[20];

void solve() {
    int n, x; cin>>n>>x;
    vector<int> v(n);
    set<int> st;
    for(auto &x : v) {
        cin>>x;
        st.insert(x);
    }

    vector<int> sorted(st.begin(), st.end());
    int sz = sorted.size();

    int base = 1;
    while(base <= (2 * sz)) base <<= 1;
    vector<int> seg(2 * base + 1);

    auto build = [&] (int n) {
        for(int i = 0; i < n; i++) {
            seg[i + n] = 0;
        }
        for(int i = n; i >= 1; i--) {
            seg[i] = seg[2 * i] + seg[2 * i + 1];
        }
    };

    auto query = [&] (int l, int r) {
        l += sz;
        r += sz;
        int sm = 0;
        while(l <= r) {
            if(l & 1) {
                sm += seg[l++];
            }
            if(!(r & 1)) {
                sm += seg[r--];
            }
            l >>= 1;
            r >>= 1;
        }
        return sm;
    };

    auto update = [&] (int ind, int val) {
        ind += sz;
        seg[ind] = val;
        while(ind > 1) {
            ind >>= 1;
            seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
        }
    };

    build(sz);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int l = lower_bound(sorted.begin(), sorted.end(), max(0LL, pwr[x - 1] - v[i])) - sorted.begin();
        int r = upper_bound(sorted.begin(), sorted.end(), max(0LL, pwr[x] - v[i] - 1)) - sorted.begin() - 1;

        ans += (n - i) * query(l, r);
        
        int ind = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
        update(ind, i + 1);
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pwr[0] = 1;

    for(int i = 1; i <= 18; i++) pwr[i] = pwr[i - 1] * 10;
    pwr[19] = LLONG_MAX;

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