#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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

const double PI = acos(-1);
// #define sz(a) (int) a.size()
 
// namespace fft {
//     typedef complex<double> base;
//     void fft(vector<base> &v, bool inv){
//         vector<base> w(v.size());
//         for(int i=2; i<= sz(v); i<<=1){
//             int bsz = v.size() / i;
//             base ang(cos(2 * PI / i), sin(2 * PI / i));
//             if(inv) ang = base(1, 0) / ang;
//             for(int j=0; j<bsz; j++){
//                 for(int k=0; k<i; k++){
//                     w[k] = v[bsz * k + j];
//                 }
//                 base pw(1, 0);
//                 for(int k=0; k<i/2; k++){
//                     base a = w[2*k], b = w[2*k+1] * pw;
//                     v[bsz * k + j] = a + b;
//                     v[bsz * k + j + v.size()/2] = a - b;
//                     pw *= ang;
//                 }
//             }
//         }
//         if(inv){
//             for(int i=0; i< sz(v); i++){
//                 v[i] /= v.size();
//             }
//         }
//     }
//     vector<int> multiply(vector<int> &v, vector<int> &w){
//         vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
//         int n = 1;
//         while(n < max(sz(v), sz(w))) n <<= 1;
//         n <<= 1;
//         fv.resize(n);
//         fw.resize(n);
//         fft(fv, 0);
//         fft(fw, 0);
//         for(int i=0; i<n; i++) fv[i] *= fw[i];
//         fft(fv, 1);
//         vector<int> ret(n);
//         for(int i=0; i<n; i++) ret[i] = (round(fv[i].real()) > 0);  // remove this to get actual coefficients instead of just booleans
//         return ret;
//     }
// };

// using namespace fft;


typedef vector<int>vi;
namespace FFT {
    typedef long long ll;
    typedef long double ld;
    struct base {
        typedef double T; T re, im;
        base() :re(0), im(0) {}
        base(T re) :re(re), im(0) {}
        base(T re, T im) :re(re), im(im) {}
        base operator + (const base& o) const { return base(re + o.re, im + o.im); }
        base operator - (const base& o) const { return base(re - o.re, im - o.im); }
        base operator * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
        base operator * (ld k) const { return base(re * k, im * k); }
        base conj() const { return base(re, -im); }
    };

    const int N = 17;/// ceil of log(a+b)
    const int MAXN = (1 << N);
    base w[MAXN];
    base f1[MAXN];
    int rev[MAXN];

    void build_rev(int k) {
        static int rk = -1;
        if (k == rk)return; rk = k;
        int K=1<<k;
        for (int i = 1; i <= K; i++) {
            int j = rev[i - 1], t = k - 1;
            while (t >= 0 && ((j >> t) & 1)) { j ^= 1 << t; --t; }
            if (t >= 0) { j ^= 1 << t; --t; }
            rev[i] = j;
        }
    }

    void fft(base *a, int k) {
        build_rev(k);
        int n = 1 << k;
        for (int i = 0; i < n; i++) if (rev[i] > i) swap(a[i], a[rev[i]]);
        for (int l = 2, ll = 1; l <= n; l += l, ll += ll) {
            if (w[ll].re == 0 && w[ll].im == 0) {
                ld angle = PI / ll;
                base ww(cosl(angle), sinl(angle));
                if (ll > 1) for (int j = 0; j < ll; ++j) {
                    if (j & 1) w[ll + j] = w[(ll + j) / 2] * ww;
                    else w[ll + j] = w[(ll + j) / 2];
                }
                else w[ll] = base(1, 0);
            }
            for (int i = 0; i < n; i += l) for (int j = 0; j < ll; j++) {
                base v = a[i + j], u = a[i + j + ll] * w[ll + j];
                a[i + j] = v + u; a[i + j + ll] = v - u;
            }
        }
    }

    vi multiply(const vi& a, const vi& b) {
        int k = 1;
        int ABsize=(int)(a.size()) + (int)(b.size());
        while ((1 << k) < ABsize) ++k;
        int n = (1 << k);
        for (int i = 0; i < n; i++) f1[i] = base(0, 0);
        int Asize=(int)(a.size());
        int Bsize=(int)(b.size());
        for (int i = 0; i < Asize; i++)f1[i]= f1[i] + base(a[i], 0);
        for (int i = 0; i < Bsize; i++)f1[i]= f1[i] + base(0, b[i]);
        fft(f1, k);
        for (int i = 0; i < 1 + n / 2; i++){
            base p= f1[i] + f1[(n - i) % n].conj();
            base _q= f1[(n - i) % n] - f1[i].conj();
            base q(_q.im, _q.re);
            f1[i] = (p * q) * 0.25;
            if (i > 0) f1[(n - i)] = f1[i].conj();
        }
        for(int i = 0; i < n; i++)f1[i]= f1[i].conj();
        fft(f1, k);
        vi r(ABsize);
        int Rsize=(int)(r.size());
        for(int i = 0; i < Rsize; i++)r[i] = ll(f1[i].re / n + 0.5);
        /// if only ith value can be made possible or not asked
    //    for(int i = 0; i < Rsize; i++)r[i] = (r[i]!=0);
        return r;
    }
};

using namespace FFT;

const int B = 555;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    for(auto &x : v) cin >> x, mx = max(mx, x);

    vector<vector<int>> cur(B + 10);
    for(int i = 0; i < n; i++) {
        cur[i / B].push_back(v[i]);
    }

    vector<int> pf(mx + 1);
    int ans = 0;
    
    for(int i = 0; i < B && sz(cur[i]) > 0; i++) {
        vector<int> fq(mx + 1);
        for(int j = 0; j < sz(cur[i]); j++) {
            for(int k = j + 1; k < sz(cur[i]); k++) if(1 <= cur[i][k] - cur[i][j] && cur[i][k] - cur[i][j] <= mx) {
                ans += pf[cur[i][k] - cur[i][j]];
                ans += fq[cur[i][k] - cur[i][j]];
            }
            fq[cur[i][j]] += 1;
        }

        auto prod = multiply(pf, pf);
        for(int j = 0; j <= mx && j < sz(prod); j++) if(prod[j]) {
            ans += fq[j];
        }
        
        for(auto x : cur[i]) pf[x] += 1;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}