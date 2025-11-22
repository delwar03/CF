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
        Node* link[10];
        int pf, en;
    } *root;

    Trie() : root(new Node()) {}

    void add(string s) {
        auto cur = root;
        for(auto c : s) {
            if(!cur->link[c - '0']) cur->link[c - '0'] = new Node();
            cur = cur->link[c - '0'];
            cur->pf++;
        }
        cur->en++;
    }

    void del(string s) {
        auto cur = root;
        for(auto c : s) {
            cur = cur->link[c - '0'];
            cur->pf--;
        }
        cur->en--;
    }

    bool get(string s) {
        auto cur = root;
        for(auto c : s) {
            if(!cur->link[c - '0']) return false;
            cur = cur->link[c - '0'];
        }
        return true;
    }
} tr;

void solve() {
    int n; cin >> n;
    vector<string> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end(), [&] (const auto& a, const auto& b) {
        return sz(a) > sz(b);
    });

    for(auto s : v) {
        if(tr.get(s)) {cout << "NO" << endl; return; }
        tr.add(s);
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }
}