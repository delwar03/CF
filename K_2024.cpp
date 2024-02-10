#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, m;
vector<string> v;
vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
    if(!isValid(i, j)) return;
    if(v[i][j] == '#') return;
    v[i][j] = '#';
    for(int d = 0; d < 4; d++) {
        int nrow = i + dir[d][0];
        int ncol = j + dir[d][1];
        dfs(nrow, ncol);
    }
}

void solve() {
    cin>>n>>m;
    cout<<__gcd(n, m)<<endl;
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