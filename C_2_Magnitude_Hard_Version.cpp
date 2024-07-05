#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int pow2[N];

void solve() {
    int n; cin>>n;
    int sum = 0, mn = 0, ways = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        sum += x;
        mn = sum < mn ? sum : mn;
    }
    int k = sum - 2 * mn;
    // cout<<k<<endl;

    if(mn == 0) {
        ways = pow2[n];
    } else {
        sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i];
            if(sum == mn) {
                ways = (ways + pow2[n - 1 - i + cnt]) % mod;
            }
            if(sum >= 0) cnt++;
        }
    }
    cout<<ways<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pow2[0] = 1;

    for(int i = 1; i < N; i++) {
        pow2[i] = 2 * pow2[i - 1] % mod;
    }

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