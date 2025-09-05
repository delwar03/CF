#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iomanip>

#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()

using namespace std;

int dx[] = {0, -1, 0, 1, -1, 5, 1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 5, 0, 1, 1, 1};

struct Point {
    int x, y;
    Point(): x(0), y(0) {}
    Point(int xx, int yy): x(xx), y(yy) {}
};

void solve() {
    string s; cin >> s;
    vector<Point> poly;
    int x = 0, y = 0;
    poly.push_back(Point(x, y));
    for(auto c : s) {
        if(c == '5') break;
        x += dx[c - '0'], y += dy[c - '0'];
        poly.push_back(Point(x, y));
    }

    
    assert(x == 0 && y == 0);
    
    int n = sz(poly);
    double area = 0;
    for(int i = 0; i < n; i++) area += poly[i].x * poly[(i + 1) % n].y - poly[(i + 1) % n].x * poly[i].y;
    if(area < 0) area = -area;

    cout << fixed << setprecision(10) << area / 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}