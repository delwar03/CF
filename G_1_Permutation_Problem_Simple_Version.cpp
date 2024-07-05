#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    vector<int> a(n + 1), b(n + 1), cnt(n + 1), vis(n + 1), res(n + 1);
    vector<int> mp_a[n + 1], mp_b[n + 1];

    for(int i = 1; i <= n; i++) {
        int g = __gcd(v[i], i);
        a[i] = v[i] / g;
        b[i] = i / g;

        mp_a[a[i]].push_back(i);
        mp_b[b[i]].push_back(i);
    }

    long long ans = 0;

    for(int x = 1; x <= n; x++) {

        for(auto i : mp_b[x]) {
            cnt[a[i]]++;
        }

        for(int y = x; y <= n; y += x) {
            for(auto i : mp_a[y]) {
                int val = b[i];

                if(vis[val] != x) {
                    res[val] = 0;
                    for(int z = val; z <= n; z += val) {
                        res[val] += cnt[z];
                    }
                    vis[val] = x;
                }
                ans += res[val];
            }
        }
        for(auto i : mp_b[x]) {
            cnt[a[i]]--;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(b[i] == 1) ans--;
    }

    cout<<ans / 2<<endl;
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