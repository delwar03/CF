#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<int> getFactors(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(n / i != i) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.rbegin(), res.rend());
    return res;
}

void solve() {
    int n; cin>>n;
    int l = 1, r = n - (n & 1);
    for(int i = 1; 2 * i <= n; i++) {
        cout<<l++<<" "<<r--<<" ";
    }
    if(n & 1) cout<<n; cout<<endl;
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