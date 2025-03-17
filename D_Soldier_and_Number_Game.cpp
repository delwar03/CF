#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

int prime[N], f[N];

int getCnt(int n) {
    int cnt = 0;
    while(n > 1) {
        int di = prime[n];
        n /= di;
        cnt++;
    }
    return cnt;
}

void solve() {
    int a, b; cin>>a>>b;
    cout<<f[a] - f[b]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    iota(prime, prime + N, 0LL);
    
    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                if(prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }
    // for(int i = 0; i < 100; i++) cerr<<prime[i]<<" ";

    for(int i = 2; i < N; i++) f[i] = getCnt(i);


    for(int i = 2; i < N; i++) f[i] += f[i - 1];

    // for(int i = 0; i < 100; i++) cerr<<i<<" -> "<<f[i]<<"\n";

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
