#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    int cnt2 = 0, cnt4 = 0;
    for(auto &x : v) {
        cin>>x;

        cnt2 -= mp[x] / 2;
        cnt4 -= mp[x] / 4;

        mp[x]++;
        cnt2 += mp[x] / 2;
        cnt4 += mp[x] / 4;
    }

    int q; cin>>q;
    while(q--) {
        char ch;
        int x; cin>>ch>>x;

        cnt2 -= mp[x] / 2;
        cnt4 -= mp[x] / 4;
        
        if(ch == '+') {
            mp[x]++;
        } else {
            mp[x]--;
        }

        cnt2 += mp[x] / 2;
        cnt4 += mp[x] / 4;

        if(cnt4 >= 1 && cnt2 >= 4) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
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
    1 -> 1
    2 -> 2
    4 -> 4
    5 -> 2
o/p: 
*/ 
