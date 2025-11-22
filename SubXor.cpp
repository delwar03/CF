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
        Node *link[2];
        int cnt;
    } *root;

    Trie() : root(new Node()) {}

    void add(int x) {
        auto cur = root;
        for(int i = 25; i >= 0; i--) {
            int f = x >> i & 1;
            if(!cur->link[f]) cur->link[f] = new Node();
            cur = cur->link[f];
            cur->cnt++;
        }
    }

    int get(int x, int k) {
        auto cur = root;
        int ret = 0;

        for(int i = 25; i >= 0; i--) {
            int fx = x >> i & 1, fk = k >> i & 1;
            if(fk == 1) {
                if(cur->link[fx]) ret += cur->link[fx]->cnt;
                if(!cur->link[!fx]) break;
                cur = cur->link[!fx];
            } else {
                if(!cur->link[fx]) break;
                cur = cur->link[fx];
            }
        }

        return ret;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n), pf(n);
    for(int i = 0; i < n; i++) cin >> v[i], pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) ^ v[i];

    Trie tr;
    tr.add(0);
    
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += tr.get(pf[i], k);
        tr.add(pf[i]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}