#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, c; cin>>n>>c;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> pref(n + 1), pref_mx(n + 1), suff_mx(n + 1);

    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
        pref_mx[i + 1] = max(pref_mx[i], v[i]);
    }

    for(int i = n - 1; i >= 0; i--) {
        suff_mx[i] = max(suff_mx[i + 1], v[i]);
    }

    // for(auto it : pref_mx) cerr<<it<<" "; cerr<<endl;
    // for(auto it : suff_mx) cerr<<it<<" "; cerr<<endl;

    for(int i = 0; i < n; i++) {
        int ans = 0;
        if(!i) {
            ans = (v[i] + c >= suff_mx[1] ? 0 : 1);
        } else {
            if(v[i] > pref_mx[i] && v[i] >= suff_mx[i + 1] && v[i] > v[0] + c) {
                ans = 0;
            } else {
                int sum = pref[i + 1] + c;
                if(sum >= suff_mx[i + 1]) {
                    ans = i;
                } else {
                    ans = i + 1;
                }
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/