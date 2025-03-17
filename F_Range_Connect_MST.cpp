#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int l, r, wt;
};

void solve() {
    int n, q; cin>>n>>q;
    vector<Node> que(q);
    for(auto &x : que) cin>>x.l>>x.r>>x.wt;

    sort(que.begin(), que.end(), [] (Node a, Node b) {
        return a.wt < b.wt;
    });

    set<int> st;
    for(int i = 1; i <= n; i++) st.insert(i);

    int cost = 0;

    for(int i = 0; i < q; i++) {
        int l = que[i].l, r = que[i].r, wt = que[i].wt;
        cost += wt;

        auto it = st.lower_bound(l + 1);
        while(it != st.end() && *it <= r) {
            cost += wt;
            it = st.erase(it);
        }
    }

    if(st.size() > 1) cost = -1;

    cout<<cost<<endl;
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