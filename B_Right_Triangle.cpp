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

void solve() {
    vector<pair<int, int>> v;
    for(int i = 0; i < 3; i++) {
        int x, y; cin>>x>>y;
        v.push_back({x, y});
    }

    auto getDist = [&] (pair<int, int> a, pair<int, int> b) {
        return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
    };
    vector<int> dist;
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            dist.push_back(getDist(v[i], v[j]));
        }
    }
    sort(dist.rbegin(), dist.rend());
    cout<<(dist[0] == dist[1] + dist[2] ? "Yes" : "No")<<endl;
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