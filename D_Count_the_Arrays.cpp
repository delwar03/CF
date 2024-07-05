#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int fact[N], revFact[N], inv[N];

void solve() {
    int n, m; cin>>n>>m;

    auto binPow = [&] (int a, int b) {
        int res = 1;
        while(b > 0) {
            if(b & 1) {
                res = (res * a) % M;
            }
            a = (a * a) % M;
            b >>= 1;
        }
        return res;
    };

    auto nCr = [&] (int n, int r) {
        return (((fact[n] * revFact[r]) % M) * revFact[n - r]) % M;
    };

    int ans = nCr(m, n - 1);
    ans = (ans * (n - 2)) % M;
    ans = (ans * binPow(2, n - 3)) % M;
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    inv[1] = 1;

    for(int a = 2; a < N; a++) {
        inv[a] = M - (M / a) * inv[M % a] % M;
    }
    
    fact[0] = fact[1] = revFact[0] = revFact[1] = 1;

    for(int i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        revFact[i] = (inv[i] * revFact[i - 1]) % M;
    }

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