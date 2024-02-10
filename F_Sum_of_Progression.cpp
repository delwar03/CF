#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<vector<array<int, 3>>> quer(n + 1);

    for(int i = 0; i < q; i++) {
        int s, d, k; cin>>s>>d>>k;
        s--;
        quer[d].push_back({s, k, i});
    }
    vcetor<int> ans(n);

    for(int d = 1; d <= n; d++) {
        if(quer[d].size()) {
            vector<int> sum(n), coffSum(n);
            for(int i = 0; i < n; i++) {
                if(i >= d) {
                    sum[i] = sum[i - d];
                    coffSum[i] = coffSum[i - d];
                }

                sum[i] += v[i];
                coffSum[i] += (i / d) * v[i];
            }

            for(auto [s, k, i] : quer[d]) {
                ans[i] = coffSum[s + (k - 1) * d];
                if(s - d >= 0) ans[i] -= coffSum[s - d];

                
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 