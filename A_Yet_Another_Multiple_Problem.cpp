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

int n, m;

void solve() {
    vector<int> can(10, 1);
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        can[x] = 0;
    }
    
    vector<int> vis(n), prv(n), id(n);
    queue<int> q;
    q.push(0);

    int f = 1;

    while(sz(q)) {
        auto x = q.front();
        q.pop();
        for(int i = f; i < 10; i++) {
            if(!can[i]) continue;
            int cur = (10 * x + i) % n;
            if(!vis[cur]) {
                q.push(cur);
                vis[cur] = 1;
                id[cur] = i;
                prv[cur] = x;
            }
        }
        f = 0;
    }

    if(!vis[0]) {cout<<-1<<endl; return; }
    int tmp = 0;
    string ans;
    while(1) {
        ans += to_string(id[tmp]);
        tmp = prv[tmp];
        if(tmp == 0) break;
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(cin>>n>>m) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}