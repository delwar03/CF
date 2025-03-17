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

int g[105];

int magic(int n) {
    int &ans = g[n];
    if(~ans) return ans;

    ans = 0;
    set<int> cur;
    for(int i : {2, 3, 5}) {
        if(n - i >= 0) {
            cur.insert(magic(n - i));
        }
    }
    while(cur.count(ans)) ans++;
    return ans;
}

void solve() {
    int n; cin>>n;
    cout<<(g[n] ? "First" : "Second")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(g, -1, sizeof g);

    g[0] = 0;
    for(int i = 1; i <= 100; i++) g[i] = magic(i);

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