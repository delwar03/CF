#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    string s; cin>>s;
    int m; cin>>m;
    string l, r; cin>>l>>r;
    int mx = -1;

    for(int i = 0; i < m; i++) {
        int tmp = mx + 1;
        for(char ch = l[i]; ch <= r[i]; ch++) {
            int ind = s.find(ch, tmp);
            // cerr<<ind<<endl;
            if(ind == string::npos) {
                cout<<"YES"<<endl;
                return;
            }
            mx = max(mx, ind);
        }
    }
    cout<<"NO"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/