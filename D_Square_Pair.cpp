#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
map<map<int, int>, int> mp;
int ans = 0, zero_cnt = 0;

void getFactors(vector<int> &v) {
    for(auto va : v) {
        if(va == 0) {ans += v.size() - 1 - zero_cnt++; continue;}

        map<int, int> tmp;
        int x = va;
        int i = 2;
        while(i * i <= x) {
            if(x % i == 0) {
                while(x % i == 0) {
                    x /= i;
                    tmp[i]++;
                }
            }
            i++;
        }
        if(x > 1) tmp[x]++;
        vector<int> toBeDeleted;
        for(auto &it : tmp) {
            int val = it.first;
            tmp[val] %= 2;
            if(tmp[val] == 0) toBeDeleted.push_back(val);
        }
        for(auto it : toBeDeleted) tmp.erase(it);
        if(tmp.size() == 0) tmp[0] = 0;

        map<int, int> lagbe;
        for(auto it : tmp) {
            int val = it.first;
            if(tmp[val] == 1) lagbe[val] = 1;
        }
        if(lagbe.size() == 0) lagbe[0];
        
        ans += mp[lagbe];
        mp[tmp]++;
    }
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    set<int> sq;
    getFactors(v);

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 