#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double PI = acos(-1);
 
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
    string s; cin>>s;
    int n = sz(s);
    vector<int> a(n + 1), b(n + 1);
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            a[i] += 1;
        } else if(s[i] == '0') {
            b[n - i] += 1;
        }
    }

    auto prod = multiply(a, b);

    vector<bool> bad(n + 1);
    for(int i = 0; i < sz(prod); i++) {
        if(prod[i]) {
            if(abs(n - i) <= n)
                bad[abs(n - i)] = true;
            else 
                break;
        }
    }

    // for(auto it : prod) cerr<<it<<" "; cerr<<endl;

    for(int i = 1; i <= n; i++) {
        int f = 1;
        for(int j = i; j <= n; j += i) {
            if(bad[j]) {
                f = 0;
                break;
            }
        }
        if(f) {
            cout<<i<<endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}