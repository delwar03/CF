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

struct Trie {
    struct Node {
        Node* link[26];
        int pf;
    } *root;

    vector<map<int, int>> mp;

    Trie() : root(new Node()) {
        mp.resize(N);
    }

    void add(string s) {
        auto cur = root;
        for(int i = 0; i < sz(s); i++) {
            char c = s[i];
            if(!cur->link[c - 'a']) cur->link[c - 'a'] = new Node();
            cur = cur->link[c - 'a'];
            cur->pf++;
            mp[cur->pf][i + 1]++;
        }
    }

    void del(string s) {
        auto cur = root;
        for(int i = 0; i < sz(s); i++) {
            char c = s[i];
            cur = cur->link[c - 'a'];
            if(!--mp[cur->pf][i + 1]) mp[cur->pf].erase(i + 1);
            cur->pf--;
        }
    }
} tr;

void solve() {
    int q; cin >> q;
    vector<string> v;
    vector<bool> vis(N);
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            string s; cin >> s;
            reverse(s.begin(), s.end());
            v.push_back(s);
            tr.add(s);
        } else if(t == 2) {
            int k, l; cin >> k >> l;
            cout << (tr.mp[k].count(l) ? "YES" : "NO") << endl;
            v.push_back("type-2");
        } else {
            int x; cin >> x; --x;
            if(!vis[x]) tr.del(v[x]), vis[x] = true;
            v.push_back("type-3");
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