#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 1e7 + 10;
const int INF = 1e15 + 10;

int dp[105];

int f(int n) {
    int &ans = dp[n];
    if(~ans) return ans;

    set<int> st;
    for(int i = 1; i <= n; i++) {
        if(__gcd(i, n) == 1) {
            st.insert(f(n - i));
        }
    }

    ans = 0;
    while(st.count(ans)) ans++;

    if(n % 2 == 0) assert(ans == 0);

    return ans;
}

int g[N], prime[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int xo = 0;
    for(auto &x : v) {
        cin>>x;
        xo ^= g[x];
    }
    cout<<(xo ? "Alice" : "Bob")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // memset(dp, -1, sizeof dp);
    // for(int i = 1; i <= 100; i++) {
    //     cerr<<i<<" -> "<<f(i)<<endl;
    // }

    for(int i = 0; i < N; i++) prime[i] = i;

    int ct = 1;
    g[1] = 1;

    for(int i = 3; i < N; i += 2) {
        if(prime[i] == i) {
            g[i] = ++ct;
            for(int j = 2 * i; j < N; j += i) {
                if(prime[j] == j) {
                    prime[j] = i;
                    if(j % 2)
                        g[j] = g[i];
                }
            }
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