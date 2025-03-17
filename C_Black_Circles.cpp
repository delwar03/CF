#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        v.push_back({x, y});
    }

    int xs, ys, xt, yt; cin>>xs>>ys>>xt>>yt;

    int a = xs - xt, b = ys - yt, q = a * a + b * b;


    auto getDist = [&] (int x, int y) {
        int p = abs((y - ys) * (xs - xt) + (x - xs) * (ys - yt));
        return p;
    };

    auto distPoint = [&] (int x1, int y1, int x2, int y2) {
        return (int) ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    };

    int dist = a * a + b * b;

    for(int i = 0; i < n; i++) {
        int y = getDist(v[i][0], v[i][1]);
        int d = distPoint(xt, yt, v[i][0], v[i][1]);
        int x = (sqrt(d * d - y * y));
        // cerr<<x<<" "<<y<<endl;
        if(d <= dist) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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