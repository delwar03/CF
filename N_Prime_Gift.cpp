#include "bits/stdc++.h"
using namespace std;
 
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
 
/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
typedef long long ll;
// typedef int ll;
// #pragma warning("int")
 
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 


ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 19116;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

/*
16
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
100000

*/

vector<ll> gen(vector<ll> x) {
	vector<ll> v(1, 1);
	
	for (ll y: x) {
		vector<ll> nv;
		for (__int128 k = 1; k <= 1000000000000000000LL; k *= y) {
			for (ll z: v) {
				if (k * z <= 1000000000000000000LL) nv.push_back(k * z);
			}
		}
		v = nv;
	}
	
	return v;
}
 
void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	cin >> k;
	
	vector<ll> x, y;
	for (ll i = 0; i < n; i += 2) x.push_back(a[i]);
	for (ll i = 1; i < n; i += 2) y.push_back(a[i]);
	
	vector<ll> xx = gen(x), yy = gen(y);
	
	sort(xx.begin(), xx.end());
	reverse(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
		
	ll lv = 0, rv = 1e18 + 7;
	while (lv < rv) {
		ll m = (lv + rv) / 2;
		
		ll cnt = 0, pt = -1;
		for (ll z: xx) {
			while (pt + 1 < yy.size() && yy[pt + 1] <= m / z) {
				++pt;
			}
			cnt += pt + 1;
		}
				
		if (cnt < k) lv = m + 1;
		else rv = m;
	}
	cout << lv << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("evacuation");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
	
		
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}