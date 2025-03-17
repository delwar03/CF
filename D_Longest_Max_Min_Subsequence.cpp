#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    for(auto &x : v) {
        cin>>x;
        mp[x]++;
    }
    int k = mp.size();

    auto f = [&] (int x, int y, int sz) {
        if(!mp[x]) return false;
        if(sz & 1) return (y > x);
        return (y < x);
    };

    vector<int> ans;
    vector<int> vis(n + 1, 0);

    for(auto x : v) {
        mp[x]--;
        if(vis[x]) continue;

        if(ans.size()) {
            while((ans.size() && f(ans.back(), x, ans.size())) || (ans.size() >= 2 && mp[ans.back()] && f(ans.end()[-2], x, ans.size() - 1))) {
                if(ans.size() && f(ans.back(), x, ans.size())) {
                    vis[ans.back()] = 0;
                    ans.pop_back();
                } else {
                    vis[ans.back()] = 0;
                    ans.pop_back();
                    vis[ans.back()] = 0;
                    ans.pop_back();
                }
            }
            ans.push_back(x);
            vis[x] = 1;
        } else {
            ans.push_back(x);
            vis[x] = 1;
        }
    }

    assert(ans.size() == k);

    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
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