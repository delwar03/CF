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
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Trie {
    struct Node {
        Node* link[2];
        int cnt;
    };

    Node* root;

    Trie() : root(new Node()) {}

    void add(int x) {
        auto cur = root;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            if(!cur->link[b]) cur->link[b] = new Node();
            cur = cur->link[b];
            cur->cnt++;
        }
    }

    void del(int x) {
        auto cur = root;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            if(!cur->link[b]) return;
            cur = cur->link[b];
            cur->cnt--;
        }
    }

    int minXor(int x) {
        auto cur = root;
        int ret = 0;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            if(cur->link[b] && cur->link[b]->cnt > 0) {
                cur = cur->link[b];
            } else {
                ret |= (1LL << i);
                cur = cur->link[!b];
            }
        }
        return ret;
    }
} tr;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x, tr.add(x);

    for(int i = 0; i < n; i++) {
        int mn = tr.minXor(a[i]);
        cout << mn << " \n"[i == n - 1];
        tr.del(a[i] ^ mn);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}