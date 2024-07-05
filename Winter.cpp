#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

vector<int> g[N];

void solve() {
    int n, m, q; cin>>n>>m>>q;
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int time = 0;
    vector<int> frozen(n + 1, 0);
    queue<vector<int>> que;

    auto bfs = [&] {
        while(que.size()) {
            auto vec = que.front();
            int u = vec[0], t = vec[1];
            if(t > time) break;
            que.pop();
            for(auto v : g[u]) {
                if(!frozen[v]) {
                    frozen[v] = 1;
                    que.push({v, t + 1});
                }
            }
        }
        time++;
    };

    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int u; cin>>u;
            if(!frozen[u]) {
                frozen[u] = 1;
                que.push({u, time});
            }
        } else if(type == 2) {
            int t; cin>>t;
            t = min(n , time + t);
            while(time < t) {
                bfs();
            }
        } else {
            int v; cin>>v;
            cout<<(frozen[v] ? "YES" : "NO")<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/