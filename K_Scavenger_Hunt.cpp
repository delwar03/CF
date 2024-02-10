#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<string>> v;
    map<string, int> mp;
    map<int, string> mp_ans;
    int cnt = 0;

    for(int i = 0; i < n - 1; i++) {
        string a, b; cin>>a>>b;
        v.push_back({a, b});
        if(mp.find(a) == mp.end()) { mp[a] = cnt++; mp_ans[cnt] = a; }
        if(mp.find(b) == mp.end()) { mp[b] = cnt++; mp_ans[cnt] = b; }
    }
    vector<int> graph[n + 1];
    for(auto it : v) {
        graph[mp[it[0]]].push_back(mp[it[1]]);
    }
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++) {
        for(auto child : graph[i]) indegree[child]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i = 0; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto child : graph[node]) {
            indegree[child]--;
            if(indegree[child] == 0) q.push(child);
        }
    }
    // for(auto it : ans) cout<<it<<" "; cout<<endl;
    // for(auto it : mp_ans) cout<<it.first<<" "<<it.second<<endl; cout<<endl;
    for(auto it : ans) cout<<mp_ans[it + 1]<<endl; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 