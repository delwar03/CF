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
const int N = (1LL << 19);
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Trie {
    struct Node {
        Node* link[2];
        int cnt;
    } *root;

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

    int getMex(int x) {
        auto cur = root;
        int ret = 0;
        for(int i = 30; i >= 0; i--) {
            if(!cur) break;
            int b = (x >> i) & 1;
            if(!cur->link[b]) break;
            if(cur->link[b]->cnt < (1LL << i)) {
                cur = cur->link[b];
            } else {
                cur = cur->link[!b];
                ret |= (1LL << i);
            }
        }
        return ret;
    }
} tr;

int vis[N];

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(auto &x : v) cin >> x, vis[x] = 1;

    for(int i = 0; i < N; i++) if(vis[i]) tr.add(i);

    int now = 0;
    while(m--) {
        int x; cin >> x;
        now ^= x;
        cout << tr.getMex(now) << endl;
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