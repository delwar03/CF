#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class SGTree {

public:
    vector<int> seg;
    
    SGTree() {}
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    int query(int ind, int low, int high, int l, int r) {

        if(l > high || r < low) return 0;
        if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        return max(query(2 * ind + 1, low, mid, l, r), query(2 * ind + 2, mid + 1, high, l, r));
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int cnt[N], pf[N], sf[N];
vector<int> di[105];

int getCnt(int n) {
    int cnt = 0;
    for(int i = 1; i * i <= n; i++) if(n % i == 0) {
        int sq = sqrt(i);
        cnt += (sq * sq == i);
        if(n / i != i) {
            int j = n / i;
            sq = sqrt(j);
            cnt += (sq * sq == j);
        }
    }
    return cnt;
}

SGTree st(N);

void solve() {
    int l, r; cin >> l >> r;
    int mx = st.query(0, 0, N - 1, l, r);
    // cerr << mx << endl;
    int ans = *lower_bound(di[mx].begin(), di[mx].end(), l);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < N; i++) {
        int cnt = getCnt(i);
        st.update(0, 0, N - 1, i, cnt);
        di[cnt].push_back(i);
    }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}