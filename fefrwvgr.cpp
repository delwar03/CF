//#pragma GCC optimize("unroll-loops,-O3,Ofast,fast-math,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T >>;
#define int long long
#define double long double
#define pii pair<int, int>
#define tii array <int, 3>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define eps 1e-9
#define inf 1e9
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define accu(x) accumulate(all(x), (int)0)

template<unsigned P> struct modint{
    unsigned v; static unsigned mod; modint() = default;
    template<class T> modint(T x) {x %= (signed)getmod(), v = x < 0 ? x + getmod() : x;}
    static unsigned getmod() {return P > 0 ? P : mod;}
    static void setmod(unsigned m) {mod = m;}
    modint operator+() const{return *this;}
    modint operator-() const{return modint(0) - *this;}
    static modint power(modint a, int b) {if (b < 0)return power(a, -b).inv(); modint res = 1; while (b) {if (b & 1)res *= a; a *= a; b >>= 1;} return res;}
    modint inv() const{return assert(v), power(*this, getmod() - 2);}
    modint & operator+=(const modint & q) {(v += q.v) < getmod() || (v -= getmod()); return *this;}
    modint & operator-=(const modint & q) {(v -= q.v) < getmod() || (v += getmod()); return *this;}
    modint & operator*=(const modint & q) {v = 1ull * v * q.v % getmod(); return *this;}
    modint &operator/=(const modint & q) {v = 1ull * v * q.inv().v % getmod(); return *this;}
    friend modint operator+(modint p, const modint & q) {return p += q;}
    friend modint operator-(modint p, const modint & q) {return p -= q;}
    friend modint operator*(modint p, const modint & q) {return p *= q;}
    friend modint operator/(modint p, const modint & q) {return p /= q;}
    friend bool operator==(const modint & p, const modint & q) {return p.v == q.v;}
    friend bool operator!=(const modint & p, const modint & q) {return p.v != q.v;}
    friend bool operator<(const modint & p, const modint & q) {return p.v < q.v;}
    friend bool operator>(const modint & p, const modint & q) {return p.v > q.v;}
    friend bool operator<=(const modint & p, const modint & q) {return p.v <= q.v;}
    friend bool operator>=(const modint & p, const modint & q) {return p.v >= q.v;}
    friend istream & operator>>(istream & is, modint & a) {int x; is >> x; x %= (signed)getmod(); a.v = x < 0 ? x + getmod() : x; return is;}
    friend ostream & operator<<(ostream & os, const modint & a) {os << a.v; return os;}
};
template<> unsigned modint<0>::mod = 998244353;
typedef modint<0> mint;
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int tcase = 0, TCASE = 1;
    cin >> TCASE;
    while (tcase++ < TCASE) {

        int n, m;
        cin >> n >> m;
        vector <pii> inp(m);
        vector <vector <int >> prob(n + 1, vector <int>(n + 1));
        for (auto &[a, b] : inp) {cin >> a >> b; prob[a][b] = 1;}

        vector <vector <vector <mint >>> dp(n + 1, vector <vector <mint >> (n + 1, vector <mint>(n + 1)));
        vector <vector <mint >> dp_sum(n + 1, vector <mint>(n + 1));
        mint fin = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int cl = 1; cl <= n - i + 1; cl++)
            {
                for (int start = 1; start <= cl; start++)
                {
                    bool jhamela = 0;

                    int val = start;

                    for (int k = i; k < i + cl; k++)
                    {
                        if (prob[k][val]) {jhamela = 1; break;}
                        val++;
                        if (val > cl) val = 1;
                    }
                    if (jhamela) continue;
                    
                    for (int back = 1; back < i; back++)
                    {
                        for (int back_start = 1; back_start <= i - back; back_start++)
                        {
                            if (back_start == 1 && start == i - back + 1) continue;
                            dp[i][cl][start] += dp[back][i - back][back_start];
                        }

                    }
                    if (i == 1) dp[i][cl][start] = 1;
                    // dp_sum[i][cl] += dp[i][cl][start];
                    if (cl == n - i + 1) fin += dp[i][cl][start];
                }
            }
        }

        cout << fin << "\n";

    }

    return 0;
}
