#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 27;
const int INF = 1e15 + 10;
int n, m, ans = 0;
vector<int> g[N], vis(N);
string order;
bool cmp(string a, string b) {
    int p1 = 0, p2 = 0;
    for(int i = 0; i < min(a.size(), b.size()) && p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }
    if(p1 == p2 && a.size() != b.size()) return a.size() < b.size();
    return p1 < p2;
}


void solve() {
    cin>>n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    for(int i = 0; i < n - 1; i++) {
        string a = v[i], b = v[i + 1];
        int l = min(a.size(), b.size());
        for(int j = 0; j < l; j++) {
            if(a[j] != b[j]) {
                g[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }

    int Indegree[26] = {0};
    for(int u = 0; u < 26; u++) {
        for(auto v : g[u]) Indegree[v]++;
    }
    queue<int> q;
    for(int i = 0; i < 26; i++) {
        if(Indegree[i] == 0) q.push(i);
    }
    string ans;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u + 'a');
        for(auto v : g[u]) {
            Indegree[v]--;
            if(Indegree[v] == 0) q.push(v);
        }
    }
    order = ans;
    vector<string> tmp = v;
    sort(tmp.begin(), tmp.end(), cmp);
    bool hobe = true;
    for(int i = 0; i < n; i++) {
        if(v[i] != tmp[i]) hobe = false;
    }
    if(hobe) cout<<ans<<endl;
    else cout<<"Impossible\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 