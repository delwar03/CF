#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

class DisjointSet {
    
public:
    vector<int> rank, parent, sz;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }

    void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
};
    vector<int> bin = {
        1, 10, 11, 100, 101, 
        110, 111, 1000, 1001, 1010, 
        1011, 1100, 1101, 1110, 1111, 
        10000, 10001, 10010, 10011, 10100, 
        10101, 10110, 10111, 11000, 11001, 
        11010, 11011, 11100, 11101, 11110, 
        11111, 100000, 100001, 100010, 100011, 
        100100, 100101, 100110, 100111, 101000
    };

vector<int> getFactors(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    auto fact = getFactors(n);
    // for(auto it : fact) cerr<<it<<" "; cerr<<endl;
    auto isPossible = [&] (int len) {
        string tmp = "";
        int cnt = 0;
        for(int i = 0; i < len; i++) tmp += s[i];
        for(int i = 0; i < n / len; i++) {
            for(int j = 0; j < len; j++) {
                if(s[i * len + j] != tmp[j]) cnt++;
            }
            if(cnt > 1) return false;
        }
        return true;
    };

    int ans = INF;
    for(auto it : fact) {
        if(isPossible(it)) {
            ans = min(ans, it);
        }
    }
    reverse(s.begin(), s.end());
    for(auto it : fact) {
        if(isPossible(it)) {
            ans = min(ans, it);
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 