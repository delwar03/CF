#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    int x, y;
};

void solve() {
    int h, w, n; cin>>h>>w>>n;
    vector<Point> v(n);
    for(auto &p : v) cin>>p.x>>p.y;

    sort(v.begin(), v.end(), [&] (Point a, Point b) {
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    vector<pair<int, int>> Y;
    for(int i = 0; i < n; i++) {
        Y.push_back(make_pair(v[i].y, i));
    }

    vector<pair<int, int>> dp(n, {INF, INF});
    vector<int> par(n, -1);

    for(int i = 0; i < n; i++) {
        auto it = upper_bound(dp.begin(), dp.end(), Y[i]);
        *it = Y[i];
        if(it != dp.begin()) {
            par[i] = prev(it)->S;
        } else {
            par[i] = -1;
        }
    }

    int len = lower_bound(dp.begin(), dp.end(), make_pair(INF, INF)) - dp.begin();

    vector<int> path;
    int tmp = dp[len - 1].S;
    path.push_back(tmp);
    while(par[tmp] != -1) {
        path.push_back(par[tmp]);
        tmp = par[tmp];
    }

    reverse(path.begin(), path.end());
    // for(auto it : path) cerr<<it<<" "; cerr<<endl;

    string s = "";
    int x = 1, y = 1;

    for(int i = 0; i < len; i++) {
        while(x < v[path[i]].x) {
            s += "D";
            x++;
        }
        while(y < v[path[i]].y) {
            s += "R";
            y++;
        }
    }

    while(x < h) {
        s += "D";
        x++;
    }
    while(y < w) {
        s += "R";
        y++;
    }

    cout<<len<<endl;
    cout<<s<<endl;
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