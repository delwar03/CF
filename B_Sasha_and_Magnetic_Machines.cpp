#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i ^ (n / i)) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(auto &x : v) {cin>>x; sum += x; }
    sort(v.begin(), v.end());
    int ans = sum;

    for(int i = 0; i < n; i++) {
        auto fact = getFactors(v[i]);
        for(auto it : fact) {
            int cur = sum;
            cur -= v[i];
            cur += v[i] / it;
            cur += v[0] * (it - 1);
            ans = min(ans, cur);
        }
    }
    cout<<ans<<endl;
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