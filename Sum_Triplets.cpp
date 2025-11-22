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
#define sz(a) (int) a.size()
 
namespace fft {
    typedef complex<double> base;
    void fft(vector<base> &v, bool inv){
        vector<base> w(v.size());
        for(int i=2; i<= sz(v); i<<=1){
            int bsz = v.size() / i;
            base ang(cos(2 * PI / i), sin(2 * PI / i));
            if(inv) ang = base(1, 0) / ang;
            for(int j=0; j<bsz; j++){
                for(int k=0; k<i; k++){
                    w[k] = v[bsz * k + j];
                }
                base pw(1, 0);
                for(int k=0; k<i/2; k++){
                    base a = w[2*k], b = w[2*k+1] * pw;
                    v[bsz * k + j] = a + b;
                    v[bsz * k + j + v.size()/2] = a - b;
                    pw *= ang;
                }
            }
        }
        if(inv){
            for(int i=0; i< sz(v); i++){
                v[i] /= v.size();
            }
        }
    }
    vector<int> multiply(vector<int> &v, vector<int> &w){
        vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
        int n = 1;
        while(n < max(sz(v), sz(w))) n <<= 1;
        n <<= 1;
        fv.resize(n);
        fw.resize(n);
        fft(fv, 0);
        fft(fw, 0);
        for(int i=0; i<n; i++) fv[i] *= fw[i];
        fft(fv, 1);
        vector<int> ret(n);
        for(int i=0; i<n; i++) ret[i] = (round(fv[i].real()) > 0);  // remove this to get actual coefficients instead of just booleans
        return ret;
    }
};

using namespace fft;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    for(auto &x : v) cin >> x, mx = max(mx, x);

    vector<int> fq(mx + 1);
    for(auto x : v) fq[x] += 1;

    auto prod = multiply(fq, fq);

    int ans = 0;
    for(int i = 0; i <= mx && i < sz(prod); i++) if(prod[i]) {
        ans += fq[i];
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}