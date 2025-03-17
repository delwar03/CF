#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int l, r, k, idx;
};

int timer, cur;
vector<int> FQ(N), invFQ(N);

void solve() {
    int n, m; cin>>n>>m;
    vector<int> col(n + 1), g[n + 1];
    for(int i = 1; i <= n; i++) cin>>col[i];

    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> st(n + 1), en(n + 1), lt(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        st[u] = ++timer;
        lt[timer] = col[u];
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
            }
        }
        en[u] = timer;
    };

    dfs(1, 0);

    vector<Node> que(m);

    for(int i = 0; i < m; i++) {
        int u, k; cin>>u>>k;
        que[i] = {st[u], en[u], k, i};
    }

    sort(que.begin(), que.end(), [] (Node a, Node b) {
        if(a.l / BLK != b.l / BLK) return a.l / BLK < b.l / BLK;
        return (((a.l / BLK) & 1) ? a.r < b.r : a.r > b.r);
    });
    
    vector<int> BIT(2 * n);

    auto upd = [&] (int i, int val) {
        if(i <= 0) return;
        for(; i <= n; i += i & -i) BIT[i] += val;
    };

    auto sum = [&] (int i) {
        if(i <= 0) return 0LL;
        int sm = 0;
        for(; i; i -= i & -i) sm += BIT[i];
        return sm;
    };

    auto query = [&] (int l, int r) {
        if(l > r) return 0LL;
        return sum(r) - sum(l - 1);
    };

    auto add = [&] (int x) {
        upd(FQ[x], -1);
        FQ[x]++;
        upd(FQ[x], +1);
    };

    auto del = [&] (int x) {
        upd(FQ[x], -1);
        FQ[x]--;
        upd(FQ[x], +1);
    };

    vector<int> ans(m);
    int lb = 1, rb = 0;

    for(int i = 0; i < m; i++) {
        int l = que[i].l, r = que[i].r, k = que[i].k, idx = que[i].idx;

        while(rb < r) add(lt[++rb]);
        while(lb > l) add(lt[--lb]);

        while(rb > r) del(lt[rb--]);
        while(lb < l) del(lt[lb++]);

        ans[idx] = query(k, n);
    }

    for(int i = 0; i < m; i++) cout<<ans[i]<<endl;

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