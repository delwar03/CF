#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Line {
    int x1, y1, x2, y2;
};

void solve() {
    int n, s, t; cin>>n>>s>>t;
    vector<Line> lines(n);
    for(auto &L : lines) cin>>L.x1>>L.y1>>L.x2>>L.y2;

    auto getDist = [&] (int x1, int y1, int x2, int y2) {
        double dx = x1 - x2, dy = y1 - y2;
        return (double) sqrt(dx * dx + dy * dy);
    };

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);

    double ans = 1e18;

    do {
        for(int mask = 0; mask < (1LL << n); mask++) {
            double tm = 0;
            int x = 0, y = 0;
            for(int j : ord) {
                int x1 = lines[j].x1, y1 = lines[j].y1, x2 = lines[j].x2, y2 = lines[j].y2; 
                if(mask & (1LL << j)) {
                    double d = getDist(x, y, x1, y1);
                    x = x1, y = y1;
                    tm += d / s;
                    d = getDist(x, y, x2, y2);
                    x = x2, y = y2;
                    tm += d / t;
                } else {
                    double d = getDist(x, y, x2, y2);
                    x = x2, y = y2;
                    tm += d / s;
                    d = getDist(x, y, x1, y1);
                    x = x1, y = y1;
                    tm += d / t;
                }
            }
            ans = min(ans, tm);
        }
    } while(next_permutation(ord.begin(), ord.end()));

    cout<<fixed<<setprecision(15);
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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