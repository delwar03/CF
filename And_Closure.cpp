#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inv2 = (mod + 1) >> 1;
#define M (1 << 20)
#define OR 0
#define AND 1
#define XOR 2

struct FWHT {
public:
    int P1[M], P2[M];
    int binPow(int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) (ret *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return ret;
    }

    void wt(int *a, int n, int flag = XOR) {
        if (n == 0) return;
        int m = n / 2;
        wt(a, m, flag); wt(a + m, m, flag);
        for (int i = 0; i < m; i++) {
            int x = a[i], y = a[i + m];
            if (flag == OR) a[i] = x, a[i + m] = (x + y) % mod;
            if (flag == AND) a[i] = (x + y) % mod, a[i + m] = y;
            if (flag == XOR) a[i] = (x + y) % mod, a[i + m] = (x - y + mod) % mod;
        }
    }

    void iwt(int* a, int n, int flag = XOR) {
        if (n == 0) return;
        int m = n / 2;
        iwt(a, m, flag); iwt(a + m, m, flag);
        for (int i = 0; i < m; i++) {
            int x = a[i], y = a[i + m];
            if (flag == OR) a[i] = x, a[i + m] = (y - x + mod) % mod;
            if (flag == AND) a[i] = (x - y + mod) % mod, a[i + m] = y;
            if (flag == XOR) a[i] = 1LL * (x + y) * inv2 % mod, a[i + m] = 1LL * (x - y + mod) * inv2 % mod; // replace inv2 by >>1 if not required
        }
    }

    vector<int> multiply(int n, vector<int> A, vector<int> B, int flag = XOR) {
        assert(__builtin_popcount(n) == 1);
        A.resize(n); B.resize(n);
        for (int i = 0; i < n; i++) P1[i] = A[i];
        for (int i = 0; i < n; i++) P2[i] = B[i];
        wt(P1, n, flag); wt(P2, n, flag);
        for (int i = 0; i < n; i++) P1[i] = 1LL * P1[i] * P2[i] % mod;
        iwt(P1, n, flag);
        return vector<int> (P1, P1 + n);
    }

    vector<int> pow(int n, vector<int> A, long long k, int flag = XOR) {
        assert(__builtin_popcount(n) == 1);
        A.resize(n);
        for (int i = 0; i < n; i++) P1[i] = A[i];
        wt(P1, n, flag);
        for(int i = 0; i < n; i++) P1[i] = binPow(P1[i], k);
        iwt(P1, n, flag);
        return vector<int> (P1, P1 + n);
    }
}t;

void solve() {
    int n; cin>>n;
    vector<int> F(M);
    for(int i = 0, x; i < n; i++) cin>>x, F[x] = 1;
    auto prod = t.pow(M, F, n, AND);
    int cnt = 1;
    for(int i = 1; i < sz(prod); i++) if(prod[i]) cnt++;

    cout<<cnt<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}