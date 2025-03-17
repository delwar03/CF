#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define sz(x) (int)x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 10;
const int INF = 1e18 + 10;

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

vector<int> freq(N), prod(N);

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x, freq[x]++;
    
    prod[0] = 1;

    while(k) {
        if(k & 1) {
            prod = multiply(prod, freq);
        }
        freq = multiply(freq, freq);
        k >>= 1;
    }

    for(int i = 0; i < sz(prod); i++) {
        if(prod[i]) {
            cout<<i<<" ";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/