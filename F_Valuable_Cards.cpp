#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

void solve() {
    int n, x; cin>>n>>x;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int cnt = 1;
    set<int> div;

    for(int i = 0; i < n; i++) {
        if(x % v[i] == 0) {
            vector<int> add;
            for(auto it : div) {
                if(x == v[i] * it) {
                    div.clear();
                    add.clear();
                    cnt++;
                    break;
                } else if(x % (v[i] * it) == 0) {
                    add.push_back(v[i] * it);
                }
            }
            for(auto it : add) {
                div.insert(it);
            }
            div.insert(v[i]);
        } else {
            //
        }
    }

    cout<<cnt<<endl;
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