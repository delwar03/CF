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

void solve() {
    int N, C;
    int A[200], O[200], B[200], S[200], D[200];

    cin >> N >> C;
    vector< int > undefined;
    for(int i = 0; i < C; i++) {
        string str; cin >> str;
        int tail = 0, a = 0, b = 0, o, s, d = 0;
        while(isdigit(str[tail])) a = a * 10 + str[tail++] - '0';
        if(str[tail] == '*') o = 2;
        else if(str[tail] == '<') o = 0, ++tail;
        else o = 1, ++tail;
        ++tail;

        while(isdigit(str[tail])) b = b * 10 + str[tail++] - '0';
        if(str[tail] == '+') s = 0;
        else s = 1;
        ++tail;

        while(tail < str.size()) d = d * 10 + str[tail++] - '0';
        A[i] = --a, B[i] = --b, O[i] = o, S[i] = s, D[i] = d;
        if(o == 2) undefined.push_back(i);
    }

    auto bellman_ford = [&] (vector< array<int, 3> > e) {
        vector<int> dist(N, INF);
        dist[0] = 0;
        int f = 1;
        for(int i = 0; i < N; i++) {
            f = 0;
            for(auto [u, v, d] : e) {
                if(dist[u] != INF && dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;
                    f = 1;
                }
            }
        }
        if(f) dist = {-1};
        return dist;
    };

    int ret = -1;

    for(int i = 0; i < (1 << undefined.size()); i++) {
        for(int j = 0; j < undefined.size(); j++) O[undefined[j]] = (i >> j) & 1;

        vector<array<int, 3>> edges;

        for(int k = 0; k < C; k++) {
            if(O[k] == 1) swap(A[k], B[k]);
            edges.push_back({B[k], A[k], 0});
            if(S[k] == 0) edges.push_back({B[k], A[k], -D[k]});
            else edges.push_back({A[k], B[k], D[k]});
            if(O[k] == 1) swap(A[k], B[k]);
        }

        auto dists = bellman_ford(edges);
        if(dists.empty() || *min_element(begin(dists), end(dists)) < 0) continue;
        ret = max(ret, *max_element(begin(dists), end(dists)));
    }

    if(ret == INF) cout << "inf" << endl;
    else cout << ret << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}

// problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0304