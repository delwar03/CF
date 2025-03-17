#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 1005;
const int MX = 25e8;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    int x, y, idx;
};

void solve() {
    int n; cin>>n;
    vector<Point> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i].x>>v[i].y;
        v[i].x--; v[i].y--;
        v[i].idx = i + 1;
    }

    sort(v.begin(), v.end(), [&] (Point a, Point b) {
        if(a.x / BLK != b.x / BLK) return a.x / BLK < b.x / BLK;
        return (((a.x / BLK) & 1) ? a.y < b.y : a.y < b.y);
    });

    int ans = 0;
    auto prv = v[0];

    for(int i = 1; i < n; i++) {
        ans += abs(prv.x - v[i].x) + abs(prv.y - v[i].y);
        prv = v[i];
    }

    // cerr<<ans<<endl;

    assert(ans <= MX);

    for(int i = 0; i < n; i++) cout<<v[i].idx<<" ";
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