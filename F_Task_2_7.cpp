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

void solve() {
    int a, b, L; cin>>a>>b>>L;
    
    auto gcd = [&] (int a, int b) {
        while(b > 0) {
            int k = a / b;
            a -= k * b;
            swap(a, b);
        }
        return a;
    };

    auto lcm = [&] (int a, int b) {
        return a * b / gcd(a, b);
    };

    int lc = lcm(a, b);

    if(L % lc) {cout<<"impossible"<<endl; return; }

    vector<int> di;
    for(int i = 1; i * i <= L; i++) {
        if(L % i == 0) {
            di.push_back(i);
            if(i != L / i) di.push_back(L / i);
        }
    }

    sort(di.begin(), di.end());

    for(int c : di) {
        int g = gcd(c, lc);
        c /= g;
        if(L % c == 0 && L / c == lc) {cout<<c * g<<endl; return; }
    }
    cout<<"impossible"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}