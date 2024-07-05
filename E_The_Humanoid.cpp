#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    int n, h; cin>>n>>h;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());
    vector<vector<int>> orders = {
        {2, 2, 3},
        {2, 3, 2},
        {3, 2, 2}
    };
    int ans = 0;
    for(auto order : orders) {

        int ind = 0, tmp = h, cnt = 0;

        for(int i = 0; i < n; i++) {
            if(v[i] < tmp) {
                tmp += v[i] / 2;
                cnt++;
            } else {
                if(ind < 3) {
                    tmp *= order[ind++];
                } else {
                    break;
                }
                i--;
            }
        }
        ans = max(ans, cnt);
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/