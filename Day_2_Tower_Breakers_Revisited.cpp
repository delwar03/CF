#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int g[N], prime[N];

int magic(int n) {
    if(~g[n]) return g[n];
    set<int> cur;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cur.insert(magic(i));
            if(i != 1 && i * i != n) cur.insert(magic(n / i));
        }
    }
    int mex = 0;
    while(cur.count(mex)) mex++;
    return g[n] = mex;
}

int f(int n) {
    int cnt = 0, tmp = n;
    while(tmp > 1) {
        int p = prime[tmp];
        while(tmp % p == 0) {
            tmp /= p;
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int xr = 0;
    for(auto &x : v) {
        cin>>x;
        xr ^= g[x];
    }
    cout<<(xr ? "1" : "2")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 2; i < N; i++) prime[i] = i;

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                if(prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }

    g[0] = g[1] = 0;
    
    for(int i = 2; i < N; i++) g[i] = f(i);


    // for(int i = 0; i < 101; i++) cout<<i<<" -> "<<g[i]<<endl;

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