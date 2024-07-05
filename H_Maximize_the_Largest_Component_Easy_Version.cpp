#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
int n, m;
vector<string> v;
vector<vector<int>> comp_cnt, vis;

vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0 && v[i][j] == '#';
}

int dfs(int i, int j, int cnt) {
    int tot = 1;
    vis[i][j] = 1;
    comp_cnt[i][j] = cnt;
    for(int d = 0; d < 4; d++) {
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];
        if(isValid(ni, nj)) {
            tot += dfs(ni, nj, cnt);
        }
    }
    return tot;
}

void solve() {
    cin>>n>>m;
    v.resize(n);
    for(auto &x : v) cin>>x;

    int cnt = 1, sz = 0;
    vector<int> comp_sz(1, 0);
    comp_cnt.assign(n, vector<int>(m, 0));
    vis.assign(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(isValid(i, j)) {
                sz = dfs(i, j, cnt++);
                comp_sz.push_back(sz);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int cur = 0;
        set<int> st;
        for(int j = 0; j < m; j++) {
            if(comp_cnt[i][j]) {
                st.insert(comp_cnt[i][j]);
            } else {
                cur++;
            }
            st.insert(i > 0 ? comp_cnt[i - 1][j] : 0);
            st.insert(i < n - 1 ? comp_cnt[i + 1][j] : 0);
        }
        for(auto it : st) cur += comp_sz[it];
        ans = max(ans, cur);
    }
    for(int i = 0; i < m; i++) {
        int cur = 0;
        set<int> st;
        for(int j = 0; j < n; j++) {
            if(comp_cnt[j][i]) {
                st.insert(comp_cnt[j][i]);
            } else {
                cur++;
            }
            st.insert(i > 0 ? comp_cnt[j][i - 1] : 0);
            st.insert(i < m - 1 ? comp_cnt[j][i + 1] : 0);
        }
        for(auto it : st) cur += comp_sz[it];
        ans = max(ans, cur);
    }
    cout<<ans<<endl;
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