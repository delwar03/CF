#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> ans;

void solve() {
    int n; cin>>n;
    ans.assign(n, 0);
    priority_queue<vector<int>> pq;
    int cnt = 1;
    pq.push({n, -1 * 0, n - 1});
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int l = -it[1];
        int r = it[2];
        if(l > r) continue;
        int mid = (l + r) / 2;
        ans[mid] = cnt++;
        pq.push({mid - l, -l, mid - 1});
        pq.push({r - mid, -(mid + 1), r});
    }

    for(auto it : ans) cout<<it<<" "; cout<<endl;
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