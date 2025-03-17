#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m, k; cin>>n>>m>>k;
    int w; cin>>w;
    vector<int> v(w);
    for(auto &x : v) cin>>x;
    sort(v.rbegin(), v.rend());
    priority_queue<int> pq;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int mn1 = min(i + 1, k);
            mn1 = min(mn1, n - i);
            mn1 = min(mn1, n - k + 1);
            int mn2 = min(j + 1, k);
            mn2 = min(mn2, m - j);
            mn2 = min(mn2, m - k + 1);
            
            pq.push(mn1 * mn2);
            // cerr<<"("<<mn1<<", "<<mn2<<")"<<" \n"[j == m - 1];
        }
    }

    int ans = 0;

    for(int i = 0; i < w; i++) {
        ans += v[i] * pq.top();
        // cerr<<"top: "<<pq.top()<<endl;
        pq.pop();
    }

    cout<<ans<<endl;
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