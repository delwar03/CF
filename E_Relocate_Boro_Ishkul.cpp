#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
double PI = acos(-1.0);
double eps = 1e-5;

void solve() {
    int n; cin>>n;
    vector<int> m(n), X, Y;
    for(auto &x : m) cin>>x;
    vector<vector<int>> pos;

    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        for(int j = 0; j < m[i]; j++) {
            X.push_back(x);
            Y.push_back(y);
        }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int sz = X.size();
    int mid = sz / 2;
    int x = X[mid], y = Y[mid];
    int min_dist = 0;
    for(int i = 0; i < sz; i++) {
        min_dist += (abs(X[i] - x) + abs(Y[i] - y));
    }

    if(sz % 2 == 0) {
        int temp_x = X[mid - 1], temp_y = Y[mid - 1];
        int temp_dist = 0;
        for(int i = 0; i < sz; i++) {
            temp_dist += (abs(X[i] - temp_x) + abs(Y[i] - temp_y));
        }
        if(temp_dist <= min_dist) {
            x = temp_x;
            y = temp_y;
            min_dist = temp_dist;
        }
        // cerr<<min_dist<<" "<<temp_dist<<endl;
    }
    cout<<x<<" "<<y<<" "<<min_dist<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 