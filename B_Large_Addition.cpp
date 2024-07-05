#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    int m = n;
    int cnt = 0, p = 1;
    while(m) {
        if(m / 10 == 0) p = m;
        if(cnt) {
            if(m % 10 == 0) {
                cout<<"NO"<<endl;
                return;
            }
        }
        m /= 10;
        cnt++;
    }

    if(p != 1 || n % 10 == 9) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
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