#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int q; cin>>q;
    int sz1 = 1, sz2 = 1;
    int cnt1 = 1, cnt2 = 1;
    int f = 0;
    while(q--) {
        int type, k;
        string x; cin>>type>>k>>x;
        if(!f) {
            if(type == 1) {
                sz1 += k * x.size();
                cnt1 += k * count(x.begin(), x.end(), 'a');
            } else {
                sz2 += k * x.size();
                cnt2 += k * count(x.begin(), x.end(), 'a');
                f = x != string(x.size(), 'a');
            }
        }
        if(f) {
            cout<<"YES"<<endl;
        } else {
            assert(sz2 == cnt2);
            if(sz1 < sz2) {
                if(cnt1 != sz1) {
                    cout<<"NO"<<endl;
                } else {
                    cout<<"YES"<<endl;
                }
            } else if(sz1 == sz2) {
                cout<<"NO"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
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