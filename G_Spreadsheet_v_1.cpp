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
const int MX = 2147483647;
const int MN = -2147483648;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> cols = {"A"};
unordered_map<string, int> mp;
int n, m;

int get(int i, int j) {
    return i * m + j;
}

int get(string s) {
    string col, row;
    for(int i = 0; i < sz(s); i++) {
        if('A' <= s[i] && s[i] <= 'Z') {
            col.push_back(s[i]);
        } else {
            row.push_back(s[i]);
        }
    }
    int rr = stol(row), cc = mp[col];
    return get(rr, cc);
}

set<char> op = {'+', '-', '*', '/'};

void solve() {
    cin >> n >> m;
    vector<vector<string>> grid(n, vector<string>(m));
    for(auto &x : grid) for(auto &y : x) cin >> y;
    
    int sz = n * m;
    vector<string> dp(sz, "INF");
    vector<int> g[sz], gT[sz];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            string s = grid[i][j];
            if(s[0] != '=') {
                dp[get(i, j)] = s;
            } else {
                string t;
                int id = 1;
                while(!op.count(s[id])) t.push_back(s[id++]);
                g[get(i, j)].push_back(get(t));
                gT[get(t)].push_back(get(i, j));
                t.clear();
                id++;
                while(id < sz(s)) t.push_back(s[id++]);
                g[get(i, j)].push_back(get(t));
                gT[get(t)].push_back(get(i, j));
            }
        }
    }

    vector<int> vis(sz), id(sz), ord, comp[sz];

    function<void(int, int)> dfs = [&] (int u, int f) {
        vis[u] = 1;
        for(int v : (!f ? g[u] : gT[u])) if(!vis[v]) {
            dfs(v, f);
        }
        if(!f) ord.push_back(u);
        else comp[f - 1].push_back(u), id[u] = f - 1;
    };

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(dp[i][j] != INF) vis[get(i, j)] = 1;
    for(int i = 0; i < sz; i++) if(!vis[i]) {
        dfs(i, 0);
    }
    reverse(ord.begin(), ord.end());
    vis = vector<int>(sz, 0);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(dp[i][j] != INF) vis[get(i, j)] = 1;
    int ct = 0;
    for(int u : ord) if(!vis[u]) {
        dfs(v, ++ct);
    }

    vector<int> ng[sz];

    for(int i = 0; i < ct; i++) {
        if(sz(comp[i]) > 1) {
            for(int j : comp[i]) {
                dp[j] = "CYCLE";
                
            }
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(sz(cols) < 1005) {
        auto s = cols.back();
        if(s.back() == 'Z') {
            int id = sz(s) - 1;
            while(id >= 0 && s[id] == 'Z') id--;
            if(~id) {
                s[id]++;
                for(int i = id + 1; i < sz(s); i++) s[i] = 'A';
            } else {
                for(int i = id + 1; i < sz(s); i++) s[i] = 'A';
                s.push_back('A');
            }
        } else {
            s.back()++;
        }
        cols.push_back(s);
    }

    for(int i = 0; i <= 1000; i++) mp[cols[i]] = i;

    // for(int i = 0; i < 1000; i++) cerr << cols[i] << endl;

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}