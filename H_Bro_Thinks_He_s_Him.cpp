#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class SGTree {

public:
    vector<int> seg;
    
    SGTree() {}
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &a) {
        if(low == high) {
            seg[ind] = add(seg[ind], a[low]);
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        seg[ind] = add(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {

        if(l > high || r < low) return 0LL;
        if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return add(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = add(seg[ind], val);
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = add(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int add(int a, int b) {
        return (a + b) % mod;
    }
};

int pwr[N];

void solve() {
    string s; cin>>s;
    int n = sz(s);
    int cnt[2]{};
    SGTree segF[2], segB[2];
    for(int i : {0, 1}) segF[i] = segB[i] = SGTree(n);
    int ans = pwr[n] - 1;
    for(int i = 0; i < n; i++) {
        int f = s[i] - '0';
        (ans += (cnt[f ^ 1] * pwr[n - i - 1]) % mod) %= mod;
        (cnt[f] += pwr[i]) %= mod;
        segF[f].update(0, 0, n - 1, i, pwr[i]);
        segB[f].update(0, 0, n - 1, i, pwr[n - i - 1]);
    }

    // cerr<<ans<<endl;

    int q; cin>>q;
    while(q--) {
        int i; cin>>i;
        --i;
        int f = s[i] - '0';
        (ans -= (segF[f ^ 1].query(0, 0, n - 1, 0, i) * pwr[n - i - 1]) % mod - mod) %= mod;
        (ans -= (pwr[i] * segB[f ^ 1].query(0, 0, n - 1, i, n - 1)) % mod - mod) %= mod;
        
        segF[f].update(0, 0, n - 1, i, -pwr[i]);
        segF[f ^ 1].update(0, 0, n - 1, i, pwr[i]);
        segB[f].update(0, 0, n - 1, i, -pwr[n - i - 1]);
        segB[f ^ 1].update(0, 0, n - 1, i, pwr[n - i - 1]);
        
        f ^= 1;
        s[i] ^= '0' ^ '1';
        (ans += (segF[f ^ 1].query(0, 0, n - 1, 0, i) * pwr[n - i - 1]) % mod) %= mod;
        (ans += (pwr[i] * segB[f ^ 1].query(0, 0, n - 1, i, n - 1)) % mod) %= mod;
        
        cout<<ans<<" \n"[q == 0];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pwr[0] = 1;
    for(int i = 1; i < N; i++) pwr[i] = (2 * pwr[i - 1]) % mod;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}