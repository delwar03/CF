#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int dist(const Point &p) const {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};

void solve() {
    Point start; cin>>start.x>>start.y;
    int n; cin>>n;
    vector<Point> pos(n);
    for(auto &point : pos) {
        cin>>point.x>>point.y;
    }

    vector<int> dp(1LL << n), path(1LL << n);

    for(int mask = 1; mask < (1LL << n); mask++) {
        int j = 0; // 10110011011011
        for(int i = 0; i < n; i++) {
            if(mask & (1LL << i)) {
                j = i;
                break;
            }
        }

        dp[mask] = 2 * start.dist(pos[j]) + dp[mask ^ (1LL << j)];
        path[mask] = mask ^ (1LL << j);

        for(int i = j + 1; i < n; i++) {
            if((mask & (1LL << i))) {
                int tmp = mask ^ (1LL << j) ^ (1LL << i);
                int d = start.dist(pos[i]) + pos[i].dist(pos[j]) + pos[j].dist(start) + dp[tmp];
                if(d < dp[mask]) {
                    dp[mask] = d;
                    path[mask] = tmp;
                }
            }
        }
    }

    cout<<dp[(1LL << n) - 1]<<endl;
    cout<<"0 ";
    int prvMask = (1LL << n) - 1;
    while(prvMask) {
        int curMask = path[prvMask];
        int tmp = curMask ^ prvMask;
        for(int i = 0; i < n; i++) {
            if(tmp & (1LL << i)) {
                cout<<i + 1<<" ";
            }
        }
        cout<<"0 ";
        prvMask = curMask;
    }
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