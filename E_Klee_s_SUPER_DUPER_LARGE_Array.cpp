#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;

    auto sum = [&] (int a, int b) {
        int res = b * (b + 1) / 2;
        res -= a * (a - 1) / 2;
        return res;
    };

    auto f = [&] (int m) {
        int res = sum(k, k + m);
        res -= sum(k + m + 1, k + n - 1);
        if(res < 0) res = -res;
        return res;
    };

    int l = 0, r = n - 1, best = INF;
    while(l <= r) {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        int a = f(m1), b = f(m2);
        if(a < b) {
            best = min(best, a);
            r = m2 - 1;
        } else if(b < a) {
            best = min(best, b);
            l = m1 + 1;
        } else {
            best = min(best, a);
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    cout<<best<<endl;
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