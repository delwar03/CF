#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    map<int, int> mp;
    for(int i = 0; i < 4 * n; i++) {
        int x; cin>>x;
        mp[x]++;
    }
    int mx = -1, mn = INF;

    for(auto it : mp) {
        mx = max(mx, it.first);
        mn = min(mn, it.first);
        if(it.second & 1) {
            cout<<"NO"<<endl;
            return;
        }
    }

    int area = mx * mn;

    for(auto it : mp) {
        int a = it.first;
        if(area % a == 0) {
            int b = area / a;
            if(mp[b] != mp[a]) {
                cout<<"NO"<<endl;
                return;
            }
        } else {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
