#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define sz(x) (int)x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 10;
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

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<int> V(n + 1), K(n + 1);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'V') {
            V[i] = 1;
        } else if(s[i] == 'K') {
            K[n - i] = 1;
        }
    }

    auto prod = multiply(V, K);

    int k = sz(prod);

    vector<int> impossible(k + 1, 0);

    for(int i = 0; i < k; i++) {
        if(prod[i] > 0) {
            impossible[abs(n - i)] = 1;
        }
    }

    vector<int> ans;

    for(int i = 1; i <= n; i++) {
        bool good = true;
        for(int j = i; j <= k; j += i) {
            if(impossible[j]) {
                good = false;
                break;
            }
        }
        if(good) ans.push_back(i);
    }

    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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