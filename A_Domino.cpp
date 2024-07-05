#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
vector<int> freq(N, 0);

void solve() {
    int n; cin>>n;
    int cnt1 = 0, cnt2 = 0;
    bool f = false;

    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        if((x + y) & 1) f = true;

        if(x & 1) cnt1++;
        if(y & 1) cnt2++;
    }

    if((cnt1 + cnt2) & 1) {
        cout<<-1<<endl;
    } else {
        if(cnt1 % 2 == 0) {
            cout<<0<<endl;
        } else {
            if(f) {
                cout<<1<<endl;
            } else {
                cout<<-1<<endl;
            }
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
o/p: 
*/ 
