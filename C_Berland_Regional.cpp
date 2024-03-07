#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> uni(n);
    for(auto &x : uni) cin>>x;
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        mp[uni[i]].push_back(x);
    }
    for(auto &it : mp) {
        auto &v = it.second;
        sort(v.begin(), v.end());
    }
    for(auto &it : mp) {
        auto &v = it.second;
        for(int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
    }
    map<int, vector<int>> canContribute;
    for(auto &it : mp) {
        int id = it.first;
        auto v = it.second;
        vector<int> maxTeam(v.size(), 0);
        for(int i = 0; i < v.size(); i++) {
            int p = (v.size() % (i + 1)) - 1;
            int canNot = p < 0 ? 0 : v[p];
            maxTeam[i] = v.back() - canNot;
        }
        canContribute[id] = maxTeam;
    }

    for(int i = 1; i <= n; i++) {
        int sm = 0;
        vector<int> willBeDeleted;
        for(auto &it : canContribute) {
            int id = it.first;
            auto &v = it.second;
            if(i - 1 >= v.size()) {
                willBeDeleted.push_back(id);
            } else {
                sm += v[i - 1];
            }
        }
        for(auto it : willBeDeleted) {
            canContribute.erase(it);
        }
        cout<<sm<<" \n"[i == n];
    }
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