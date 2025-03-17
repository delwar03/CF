#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int dp[1005][1024]; // (ind, mask)

void solve() {
    int n, m; cin>>n>>m;
    bitset<10> bst; cin>>bst;
    int s = (int) bst.to_ulong();

    vector<vector<int>> edges(m, vector<int>(3, 0)); // (wt, cure, symptomps)

    for(auto &x : edges) {
        cin>>x[0];
        cin>>bst;
        x[1] = (int) bst.to_ulong();
        cin>>bst;
        x[2] = (int) bst.to_ulong();
    }

    vector<int> dist(1024, INF);
    set<vector<int>> st; // (dist, node)
    st.insert({0, s});
    dist[s] = 0;

    while(st.size()) {
        auto vec = *st.begin();
        st.erase(st.begin());
        int mask = vec[1];

        for(auto it : edges) {
            int newMask = (mask & (~it[1])) | it[2];
            if(dist[mask] + it[0] < dist[newMask]) {
                dist[newMask] = dist[mask] + it[0];
                st.insert({dist[newMask], newMask});
            }
        }
    }

    cout<<(dist[0] == INF ? -1 : dist[0])<<endl;
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