#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k, m; cin>>n>>k>>m;
    vector<int> v(n);
    map<int, int> mp;
    int mx = 0;
    for(auto &x : v) {
        cin>>x;
        int p = x % m;
        mp[p]++;
        mx = mp[p] > mx ? mp[p] : mx;
    }
    if(mx >= k) {
        cout<<"Yes"<<endl;
        int val;
        for(auto it : mp) {
            if(it.second == mx) {
                val = it.first;
                break;
            }
        }
        int cnt = 0;
        for(auto it : v) {
            if((it % m) == val) {
                cout<<it<<" ";
                cnt++;
            }
            if(cnt == k) break;
        }
        cout<<endl;
    } else {
        cout<<"No"<<endl;
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