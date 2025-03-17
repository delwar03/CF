#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        if(!mp.count(v[i])) {
            mp[v[i]] = i;
        }
    }

    int ans = 0;

    for(auto it : mp) {
        int sm = 0, ind = it.second;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int j = ind + 1; j < n; j++) {
            if(pq.size() == k - 2) {
                ans = max(ans, v[ind] + sm + v[j]);
            }
            pq.push(v[j]);
            sm += 2 * v[j];
            if(pq.size() > k - 2) {
                sm -= 2 * pq.top();
                pq.pop();
            }
        }
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