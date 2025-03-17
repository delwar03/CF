#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n, m; cin>>n>>m;
    vector<int> g[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> col(n + 1, -1);
    col[1] = 0;

    function<bool(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(col[v] == -1) {
                col[v] = !col[u];
                if(!dfs(v, u)) return false;
            } else if(col[v] == col[u]) {
                return false;
            }
        }
        return true;
    };

    if(dfs(1, 0)) { // bi-partite
        cout<<"Bob"<<endl;

        vector<int> one_colored, two_colored;
        for(int i = 1; i <= n; i++) {
            if(col[i] == 1) {
                one_colored.push_back(i);
            } else {
                two_colored.push_back(i);
            }
        }

        for(int i = 1; i <= n; i++) {
            int col1, col2; cin>>col1>>col2;
            int mn_col = min(col1, col2);
            if(mn_col == 1 && one_colored.size()) {
                cout<<one_colored.back()<<" "<<1<<endl;
                one_colored.pop_back();
            } else if(mn_col == 2 && two_colored.size()) {
                cout<<two_colored.back()<<" "<<2<<endl;
                two_colored.pop_back();
            } else if(!one_colored.size()) {
                int cur_col = (col1 == 1 ? col2 : col1);
                cout<<two_colored.back()<<" "<<cur_col<<endl;
                two_colored.pop_back();
            } else {
                int cur_col = (col1 == 2 ? col2 : col1);
                cout<<one_colored.back()<<" "<<cur_col<<endl;
                one_colored.pop_back();
            }
        }
    } else {
        cout<<"Alice"<<endl;
        for(int i = 1; i <= n; i++) {
            cout<<1<<" "<<2<<endl;
            int x, y; cin>>x>>y;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
