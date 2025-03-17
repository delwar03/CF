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

int g[20][20];

bool isValid(int i, int j) {
    return i >= 1 && i <= 15 && j >= 1 && j <= 15;
}

int magic(int i, int j) {
    if(!isValid(i, j)) return INF;
    int &ans = g[i][j];
    if(~ans) return ans;

    ans = 0;
    set<int> st;

    st.insert(magic(i - 2, j + 1));
    st.insert(magic(i - 2, j - 1));
    st.insert(magic(i + 1, j - 2));
    st.insert(magic(i - 1, j - 2));

    while(st.count(ans)) ans++;
    return ans;
}

void solve() {
    int n; cin>>n;
    int xr = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        xr ^= g[x][y];
    }
    cout<<(xr ? "First" : "Second")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(g, -1, sizeof g);

    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j <= 15; j++) {
            g[i][j] = magic(i, j);
        }
    }

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