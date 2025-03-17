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

int n;
int arr[31][31];
int g[31][31][31][31];

set<int> primes = {2, 3, 5, 7};

bool allPrime(int a, int b, int c, int d) {
    if(a == c && b == d) return true;
    for(int i = a; i <= c; i++) {
        for(int j = b; j <= d; j++) {
            if(!primes.count(arr[i][j])) return false;
        }
    }
    return true;
}

int magic(int a, int b, int c, int d) {
    int &ans = g[a][b][c][d];
    if(~ans) return ans;

    ans = 0;
    if(allPrime(a, b, c, d)) return ans;

    vector<int> vis(100, 0);

    for(int i = a + 1; i <= c; i++) {
        vis[magic(a, b, i - 1, d) ^ magic(i, b, c, d)] = 1;
    }

    for(int j = b + 1; j <= d; j++) {
        vis[magic(a, b, c, j - 1) ^ magic(a, j, c, d)] = 1;
    }

    for(int i = 0; i < 100; i++) {
        if(!vis[i]) {
            ans = i;
            break;
        }
    }

    return ans;
}

void solve() {
    cin>>n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin>>arr[i][j];
        }
    }
    memset(g, -1, sizeof g);

    cout<<(magic(1, 1, n, n) ? "First" : "Second")<<endl;
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