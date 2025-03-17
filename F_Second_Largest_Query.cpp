#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

#define f first
#define s second

#define lc (id << 1)
#define rc (id << 1 | 1)

struct Node {
    int mx_1, cnt_1, mx_2, cnt_2;
    Node() : mx_1(0), cnt_1(0), mx_2(0), cnt_2(0) {}
    Node(int a, int b, int c, int d) : mx_1(a), cnt_1(b), mx_2(c), cnt_2(d) {}
};

int n, q;
vector<int> v;
vector<Node> seg;

Node merge(Node a, Node b) {
    map<int, int> mp;
    mp[a.mx_1] += a.cnt_1;
    mp[a.mx_2] += a.cnt_2;
    mp[b.mx_1] += b.cnt_1;
    mp[b.mx_2] += b.cnt_2;

    vector<pair<int, int>> v;
    for(auto it : mp) {
        v.push_back({it.first, it.second});
    }

    sort(v.rbegin(), v.rend());

    return Node(v[0].f, v[0].s, v[1].f, v[1].s);
}

void pull(int id) {
    map<int, int> mp;
    mp[seg[lc].mx_1] += seg[lc].cnt_1;
    mp[seg[lc].mx_2] += seg[lc].cnt_2;
    mp[seg[rc].mx_1] += seg[rc].cnt_1;
    mp[seg[rc].mx_2] += seg[rc].cnt_2;

    vector<pair<int, int>> v;
    for(auto it : mp) {
        v.push_back({it.first, it.second});
    }

    sort(v.rbegin(), v.rend());

    seg[id] = Node(v[0].f, v[0].s, v[1].f, v[1].s);
}

void build(int id = 1, int lo = 0, int hi = n - 1) {
    if(lo == hi) {
        seg[id] = Node(v[lo], 1, 0, 0);
    } else {
        int mid = (lo + hi) >> 1;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(id);
    }
}

void upd(int i, int x, int id = 1, int lo = 0, int hi = n - 1) {
    if(lo == hi) {
        v[i] = x;
        seg[id] = Node(v[lo], 1, 0, 0);
    } else {
        int mid = (lo + hi) >> 1;
        if(i <= mid) {
            upd(i, x, lc, lo, mid);
        } else {
            upd(i, x, rc, mid + 1, hi);
        }
        pull(id);
    }
}

Node query(int l, int r, int id = 1, int lo = 0, int hi = n - 1) {

    if(l > hi || r < lo) return Node();
    if(l <= lo && hi <= r) return seg[id];

    int mid = (lo + hi) >> 1;
    auto left = query(l, r, lc, lo, mid);
    auto right = query(l, r, rc, mid + 1, hi);

    return merge(left, right);
}


void solve() {
    cin>>n>>q;
    v.resize(n);
    for(auto &x : v) cin>>x;

    seg.resize(4 * n);
    for(int i = 0; i < 4 * n; i++) seg[i] = Node();

    build();

    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int i, x; cin>>i>>x;
            --i;
            upd(i, x);
        } else {
            int l, r; cin>>l>>r;
            --l, --r;
            auto q = query(l, r);
            cout<<q.cnt_2<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
