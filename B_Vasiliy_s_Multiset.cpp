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
    } *root;

    Trie() : root(new Node()) {}

    void add(int x) {
        auto cur = root;
        for(int i = 31; i >= 0; i--) {
            int f = x >> i & 1;
            if(!cur->link[f]) cur->link[f] = new Node();
            cur = cur->link[f];
            ++cur->cnt;
        }
    }

    void del(int x) {
        auto cur = root;
        for(int i = 31; i >= 0; i--) {
            int f = x >> i & 1;
            cur = cur->link[f];
            --cur->cnt;
        }
    }

    int get(int x) {
        auto cur = root;
        int ret = 0;
        for(int i = 31; i >= 0; i--) {
            int f = x >> i & 1;
            if(cur->link[!f] && cur->link[!f]->cnt) {
                ret += (1LL << i);
                cur = cur->link[!f];
            } else {
                cur = cur->link[f];
            }
        }
        return ret;
    }
} tr;

void solve() {
    tr.add(0);
    int q; cin >> q;
    while(q--) {
        char t; int x; cin >> t >> x;
        if(t == '+') {
            tr.add(x);
        } else if(t == '-') {
            tr.del(x);
        } else {
            cout << tr.get(x) << endl;
        }
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