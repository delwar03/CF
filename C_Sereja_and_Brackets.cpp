#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int opn, cls, com;
    Node() : opn(0), cls(0), com(0) {}
    Node(int a, int b, int c) : opn(a), cls(b), com(c) {}
};

#define lc (id << 1)
#define rc (id << 1 | 1)

int n;
vector<int> tmp;

vector<Node> Seg(4 * N);

void pull(int id) {
    int cur = min(Seg[lc].opn, Seg[rc].cls);
    Seg[id].opn = Seg[lc].opn + Seg[rc].opn - cur;
    Seg[id].cls = Seg[lc].cls + Seg[rc].cls - cur;
    Seg[id].com = Seg[lc].com + Seg[rc].com + cur;
}

Node merge(Node left, Node right) {
    Node ret;
    int cur = min(left.opn, right.cls);
    ret.opn = left.opn + right.opn - cur;
    ret.cls = left.cls + right.cls - cur;
    ret.com = left.com + right.com + cur;
    return ret;
}

void build(int id, int lo, int hi) {
    if(lo == hi) {
        Seg[id] = Node(tmp[lo] == +1, tmp[lo] == -1, 0);
    } else {
        int mid = (lo + hi) >> 1;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(id);
    }
}

Node qur(int id, int lo, int hi, int l, int r) {
    if(l > hi || r < lo) return Node();
    if(l <= lo && hi <= r) return Seg[id];
    int mid = (lo + hi) >> 1;
    auto left = qur(lc, lo, mid, l, r);
    auto right = qur(rc, mid + 1, hi, l, r);
    return merge(left, right);
}

int qur(int l, int r) {
    return qur(1, 1, n, l, r).com;
}

void solve() {
    string s; cin>>s;
    n = (int) s.size();
    s = "#" + s;
    vector<int> v;
    for(auto ch : s) {
        v.push_back(ch == '(' ? +1 : -1);
    }

    tmp = v;

    build(1, 1, n);

    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<2 * qur(l, r)<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/