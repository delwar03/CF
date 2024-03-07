#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, l; cin>>n>>l;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int a, b; cin>>a>>b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        priority_queue<int> pq;
        int sum = 0;
        for(int j = i; j < n; j++) {
            pq.push(v[j][1]);
            sum += v[j][1];
            while(pq.size() && sum + v[j][0] - v[i][0] > l) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, (int) pq.size());
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
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 