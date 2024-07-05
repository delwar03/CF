#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    int sum = 0, sq_sum = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        sum += x;
        sq_sum += x * x;
    }
    int a = 4 * n;
    int b = 4 * sum;
    int c = sq_sum - k;

    auto bs = [&] {
        int l = 1, r = 1e9, ans;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a * m * m + b * m + c <= 0) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    };

    double w = (-b + sqrtl(1.0 * b * b - 4.0 * a * c)) / (2.0 * a);
    int ans = round(w);
    cout<<ans<<endl;
    // cerr<<bs()<<endl;
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