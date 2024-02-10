#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int mn, sum;
vector<int> v;

// bool hobe (int x) {
    
// }

int getMaxFactor (int x) {
    int ans = 1;
    int i = 2;
    while(i * i <= x) {
        while(x % i == 0) {x /= i; ans = i;}
        i++;
    }
    if(x > 1) ans = max(ans, x);
    return ans;
}

void solve() {
    int n; cin>>n;
    v.resize(n);
    mn = INF, sum = 0;

    for(auto &x : v) {
        cin>>x;
        sum += x;
        mn = min(mn, x);
    }
    sum -= mn * n;

    int ans = getMaxFactor(sum);
    cout<<ans<<endl;

    // cout<<getMaxFactor(n)<<endl;
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