#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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

struct Node {
    int v[3], dist;
    bool operator<(const Node him) const {
        return dist > him.dist;
    }
};

void solve() {
    int cap[3], d; cin>>cap[0]>>cap[1]>>cap[2]>>d;

    vector<int> dp(205, INF);
    vector<vector<bool>> vis(205, vector<bool>(205, 0));

    priority_queue<Node> pq;
    Node st;
    st.dist = st.v[0] = st.v[1] = 0; st.v[2] = cap[2];
    pq.push(st);

    while(sz(pq)) {
        auto cur = pq.top(); pq.pop();

        if(vis[cur.v[0]][cur.v[1]]) continue;
        vis[cur.v[0]][cur.v[1]] = 1;

        for(int i = 0; i < 3; i++) {
            dp[cur.v[i]] = min(dp[cur.v[i]], cur.dist);
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != j && cur.v[i] > 0 && cur.v[j] < cap[j]) {
                    int mn = min(cur.v[i], cap[j] - cur.v[j]);
                    Node nw = cur;

                    nw.v[i] -= mn;
                    nw.v[j] += mn;
                    nw.dist += mn;

                    pq.push(nw);
                }
            }
        }
    }

    for(int i = d; i >= 0; i--) {
        if(dp[i] != INF) {
            cout<<dp[i]<<" "<<i<<endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}