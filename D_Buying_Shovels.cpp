#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, k;

vector<int> getFactors(int n) {
    vector<int> res;
    res.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            if(i <= k) res.push_back(i);
            if(i != n / i && n / i <= k) {
                res.push_back(n / i);
            }
        }
    }
    if(n <= k) res.push_back(n);
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    cin>>n>>k;
    vector<int> factors = getFactors(n);
    // for(auto it : factors) cout<<it<<" "; cout<<endl; 
    int largeFactor = factors.back();
    cout<<(n + largeFactor - 1) / largeFactor<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 