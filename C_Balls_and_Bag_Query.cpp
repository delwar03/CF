#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int q; cin>>q;

    map<int, int> mp;

    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int x; cin>>x;
            mp[x]++;
        } else if(type == 2) {
            int x; cin>>x;
            if(mp[x] == 1) {
                mp.erase(x);
            } else {
                mp[x]--;
            }
        } else {
            cout<<(int) mp.size()<<endl;
        }

        // for(auto it : mp) cerr<<it.first<<" -> "<<it.second<<endl; cerr<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/