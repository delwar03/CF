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
        Node *link[26];
        int pf, en;
    } *root;

    Trie() : root(new Node()) {}

    void add(const string &s) {
        auto cur = root;
        for(char c : s) {
            int f = c - 'a';
            if(!cur->link[f]) cur->link[f] = new Node();
            cur = cur->link[f];
            cur->pf++;
        }
        cur->en++;
    }

    int get(const string &s) {
        auto cur = root;
        for(int i = 0; i < sz(s); i++) {
            int f = s[i] - 'a';
            if(cur->link[f]->pf == 1) return i + 1;
            cur = cur->link[f];
        }
        return sz(s);
    }
};

void solve() {
    int n; cin >> n;
    vector<string> v(n);
    Trie tr;
    for(auto &x : v) cin >> x, tr.add(x);

    int cnt = 0;
    for(auto x : v) cnt += tr.get(x);

    cout << cnt << endl;
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