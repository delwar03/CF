#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int prime[N];
vector<int> primes;

void solve() {
    int n; cin>>n;
    --n;
    cout<<primes[n]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(prime, prime + N, 0LL);

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

    auto f = [&] (int n) {
        int cnt = 0, i = 2;
        while(i * i <= n) {
            if(n % i == 0) {
                while(n % i == 0) n /= i;
                cnt++;
            }
            i++;
        }
        if(n > 1) cnt++;
        return cnt >= 3;
    };

    for(int i = 2; i < N; i++) {
        if(f(i)) primes.push_back(i);
    }

    // for(auto it : primes) cerr<<it<<" "; cerr<<endl;
    // cerr<<(int) primes.size()<<endl;

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